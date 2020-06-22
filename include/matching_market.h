#ifndef _MATCHING_MARKET_H_
#define _MATCHING_MARKET_H_

#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>

using namespace std;

#define MAXL 100
#define INF 100000

struct S{ //for BFS
        int idx, step;
        S(int idx,int step):idx(idx), step(step){}
};

/**
 * class:Matching_market(Market_Clearing_Prices)
 * func:    tool for computing the market clearing prices or VCG
 *          also finding the optimal seller_buyer pairs or matches to maximize social welfare (most buyer payoff sum in this case)
 *          note that VCG which is a personalized price customed to buyer's claiming prices,
 *          market-clearing prices are posted prices, they are given publicly and updated round by round
 * date: 2020-06-08
 * edit: Jingyu
 */
class Matching_market{
   
    private:
        int num_buyer;
        vector<int> sellers, buyers;
        int prices[MAXL];
        int G[MAXL][MAXL]; //adjacent matrix 0-no edge 1-unpaired 2-paired
        // vector<int> preferredSellers[MAXL]; //preferred sellers
        int Valuation[MAXL][MAXL]; //valuation of buyer i on house j
        int Valuation_Backup[MAXL];
        bool visited[MAXL];
        int pre[MAXL];
        bool matched[MAXL]; //whether this node has been matched
        int BuyerOf[MAXL]; //matching pairs spec
        int SellerOf[MAXL]; //matching pairs spec
        vector<int> matchedSellers,matchedBuyers;
        vector<int> VCG;
    public:
        //utils
        Matching_market(){}
        ~Matching_market(){}
        Matching_market(int num_buyer):num_buyer(num_buyer){}

        inline void init(int buyer_excluded = -1, int seller_excluded = -1){
            memset(prices,0,sizeof(prices));
            buyers.clear();
            sellers.clear();
            if(buyer_excluded!=-1){ //add fake buyers
                memset(Valuation_Backup,0,sizeof(Valuation_Backup));
                memcpy(Valuation_Backup,Valuation[buyer_excluded],2*num_buyer*sizeof(int));
                memset(Valuation[buyer_excluded],0,sizeof(Valuation[buyer_excluded]));
            }
            for(int i=1;i<num_buyer*2;i+=2){
                // if(i == buyer_excluded){continue;} //exclude buyer (for computing VCG)
                buyers.push_back(i);
            }
            for(int j=0;j<num_buyer*2;j+=2){
                if(j == seller_excluded){continue;}
                sellers.push_back(j);
            }
        }
        inline void restoreVals(int buyer_excluded = -1){
            if(buyer_excluded!=-1){
                memcpy(Valuation[buyer_excluded],Valuation_Backup,2*num_buyer*sizeof(int));
            }

        }
        inline void inputValuation(){
            memset(Valuation,0,sizeof(Valuation));
            for(int i=1;i<num_buyer*2;i+=2){
                for(int j=0;j<num_buyer*2;j+=2){
                    int t;cin>>t;
                    Valuation[i][j]=t;
                }
            }
        }
        inline void showPlayers(){
            cout<<"Buyers: ";
            for(int i: buyers){
                cout<<i<<" ";
            }
            cout<<endl;
            cout<<"Sellers: ";
            for(int i: sellers){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        inline void showG(){
            cout<<"Current Graph Structure:"<<endl;
             for(int i=0;i<num_buyer*2;i++){
                for(int j=0;j<num_buyer*2;j++){
                   cout<<G[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        inline void showPrices(){
             //show Current prices
            cout<<"Current prices:";
            for(int i=0;i<num_buyer*2;i+=2){
                    cout<<prices[i]<<" ";
                }
            cout<<endl;
        }
        inline void showVCG(){
            int totalVal=0;
            vector<int> res;
            cout<<">>>Final Result:"<<endl;
            for(int i:matchedSellers){
                cout<<"Buyer "<<(BuyerOf[i]-1)/2<<" bought good "<<i/2<<" at price "<<VCG[(BuyerOf[i]-1)/2]<<" with valuation "<<Valuation[BuyerOf[i]][i]<<endl;
                totalVal+=Valuation[BuyerOf[i]][i];
                res.push_back(VCG[(BuyerOf[i]-1)/2]);
            }
            cout<<"VCG prices "<<endl;
            for(auto it:res){cout<<it<<" ";}
            cout<<endl;
            cout<<"Social Welfare:"<<endl;
            cout<<totalVal<<endl;
        }
        inline int getResult(int buyer_excluded){
            // cout<<">>> ------ result ------ <<<"<<endl;
            int welfare = 0;
            // int welfare_excluded = 0; ///V^(I-i)_(B-j) total valuation except for buyer_excluded
            // cout<<"### Matched:"<<endl;
            for(int i : buyers){
                for(int j : sellers){
                    if(G[i][j]==2){
                        // cout<<"raw idx: "<<"(#"<<j<<", #"<<i<<")"; //raw index (even for seller, odd for buyer)
                        // cout<<", parsed:  buyer "<<(i-1)/2<<" bought goods "<<j/2; //human-readable idx
                        // printf(" with valuation : %d\n", Valuation[i][j]);
                        welfare += Valuation[i][j];
                        // welfare += (i==welfare_excluded)?0:Valuation[i][j]; //welfare is valuation
                        continue;
                    }
                }
            }
            // cout<<"### Final Market-clearing prices: [ ";
            // for(int i: sellers){
            //         cout<<prices[i]<<" ";
            //     }
            // cout<<"]"<<endl;
            // cout<<"### Social Welfare: "<<welfare<<endl;
            restoreVals(buyer_excluded); // restore the default valuation matrix
            return welfare;
        }
        inline int getTotalValuation(){
            int welfare = 0;
            for(int i : buyers){
                for(int j : sellers){
                    if(G[i][j]==2){
                        welfare += Valuation[i][j]; //welfare is valuation
                    }
                }
            }
            return welfare;
        }
        inline int getTotalValuationExceptBuyerAndSeller(int buyer,int seller){
            int welfare = 0;
            for(int i : matchedBuyers){
              int seller = SellerOf[i];
              welfare += (i==buyer)?0:Valuation[i][seller];
            }
            return welfare;
            // return getMarketClearingPrices(buyer, seller);
        }
        inline int getTotalValuationExceptBuyer(int buyer){
            return getMarketClearingPrices(buyer);
        }
        //return the seller buyer paired with
        inline void getMatched(){
            memset(BuyerOf, -1, sizeof(BuyerOf));
            memset(SellerOf, -1, sizeof(SellerOf));
            for(int i:buyers){matchedBuyers.push_back(i);}
            for(int j:sellers){matchedSellers.push_back(j);}
            for(int i : buyers){
                for(int j : sellers){
                    if(G[i][j]==2){
                        BuyerOf[j]=i;
                        SellerOf[i]=j;
                        break;
                    }
                }
            }
        }
        int findUnmatchedBuyer();
        int findAugmentingPath(int start, vector<int>& constricted);
        void match(int start, int end);
        //for Matching_market
        void offsetPrices();
        bool isPerfectMatching(vector<int>& constricted); //gives either perfect matching or a constricted set.
        void getPreferredSellers(); //update the graph structure
        void sellerRaisePrices(vector<int>& constricted);

        //for marketClearingPrices
        int getMarketClearingPrices(int buyer_excluded = -1, int seller_excluded = -1);
        //for VCG
        void getVCGPrices();
};

#endif //MATCHING_MARKET