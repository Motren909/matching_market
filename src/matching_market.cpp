#include<iostream>
#include<matching_market.h>
/** find a augmenting path using alternative BFS
 * */

int Matching_market::findUnmatchedBuyer(){
    for(int i: buyers){ //buyers are on the right starting from 1, that is ,1 3 5 7....
        if(!matched[i]){return i;}
    }
    return -1;
}
/**name:    findAugmentingPath 
 * func:    breadth-first search starting from an unmatched buyer 'start' on the right
 *          and find a augmenting path to an unmatched seller on the left
 * return:  the index of an unmatched seller (the augmenting path is start -> unmatched seller) or -1 for none
 * */
int Matching_market::findAugmentingPath(int start, vector<int>& constricted){
    queue<S> q;
    memset(visited, 0, sizeof(visited));
    memset(pre, -1,sizeof(pre));
    
    q.push(S(start,1));pre[start]=-1;visited[start]=1;
    // cout<<"BFS starting from: "<<start<<endl;
    while(!q.empty()){
        S cur=q.front();q.pop();
        // cout<<"step "<<cur.step<<",node:"<<cur.idx<<"(";
        // cout<<((matched[cur.idx]==1)?"matched":"unmatched")<<")";
        // cout<<endl;
        int dir = cur.step % 2; // 1-right 0-left
        if(dir == 0){//to left
            if(!matched[cur.idx]){
                //find an unpaired seller node on the left, a augmenting path is found, stop
                return cur.idx;//stop
            }
            else{//go along the paired edge
                for(int i: buyers){//filter out paired buyer
                    if(!visited[i] && G[cur.idx][i]==2){//only paired
                        q.push(S(i,cur.step+1));
                        pre[i]=cur.idx;
                        visited[i]=1;
                    }
                }
            }
            
        }
        else if(dir == 1){//to right
            constricted.push_back(cur.idx);
            for(int j: sellers){
                if(G[cur.idx][j]==1){//go along unpaired edges
                    q.push(S(j,cur.step+1));
                    pre[j]=cur.idx;
                    visited[j]=1;
                }
            }
        }

    }
    return -1;
}
/** match (start, end) by fliping the matching states of the edges on the augmenting path
 * nodes are in the following index form:
 * 0 1
 * 2 3
 * 4 5
 * 6 7
 * ...
 * */
void Matching_market::match(int start, int end){
    matched[start]=matched[end]=1;
    //start from the right
    int cur=end;
    //cout<<"Augmenting path found:";
    //cout<<cur;
    //flip the augmenting path
    while(pre[cur]!=-1){
        int pre_node = pre[cur];
        //cout<<"->"<<pre_node;
        G[cur][pre_node]=G[pre_node][cur]=(G[cur][pre_node]==2?1:2);//pair <-> unpair
        cur=pre[cur];
    }
    //cout<<endl;
   // cout<<"Matching states of nodes on the path have been flipped!"<<endl;
    // cout<<start<<"-"<<end<<" matched!"<<endl;
    return ;
}

void Matching_market::sellerRaisePrices(vector<int>& constricted){
    set<int> neighbors;
    for(int i=0;i<constricted.size();i++){
        int buyer = constricted[i];
        for(int j: sellers){//seller
            if(G[buyer][j]>0){
                neighbors.insert(j);
            }
        }
    }
    for(auto it:neighbors){
        prices[it]+=1;
        cout<<"seller #"<<it<<" raised 1 unit"<<endl;
    }
}
/** rescale the prices to make sure the minimum equals 0
 *  by minus the minimum value
 * */
void Matching_market::offsetPrices(){
    int t=INF;
    for(int i=0;i<num_buyer*2;i++){ //iterate through all the sellers
        t=min(t,prices[i]);
    }
    for(int i=0;i<num_buyer*2;i++){
        prices[i]-=t;
    }
}
/** func:   Check whether there is a perfect matching  
 *          refer to textbook page 269
 *  output: whether true for a perfect matching, or false with a constricted buyer set.
 * */
bool Matching_market::isPerfectMatching(vector<int>& constricted){
    int n=buyers.size();//number of buyers
    //even numbers are nodes on the left, odd numbers are nodes on the right.
    while(n--){
        int start = findUnmatchedBuyer();
        if(start==-1){return false;}

        constricted.clear();
        int end = findAugmentingPath(start, constricted); //alternative BFS
        if(end!=-1){
             match(start, end);
        }
        else{                   
            //cout<<"No augmenting Path found."<<endl;
            return false; //no perfect matching for this preferred seller strcture
        }
    }
    //it is a perfect matching only if n paths are found
    return true;
}
/** build the preferred seller graph by iterating through each buyer's valuation 
 * and find the one with max payoff
 * equivalent to initialize the graph structure
 * */
void Matching_market::getPreferredSellers(){
    memset(G,0, sizeof(G));
    memset(matched,0, sizeof(matched));
    for(int i: buyers){ //each odd number represents a buyer
        int maxPayoff=Valuation[i][0] - prices[0];
        vector<int> maxIdxs; maxIdxs.push_back(0);
        for(int j: sellers){ //each even number represents a seller
            int payoff = Valuation[i][j] - prices[j];
            if( payoff >=0 ){ //non-negative
                if( payoff > maxPayoff){
                    maxPayoff = payoff;
                    maxIdxs.clear();
                    maxIdxs.push_back(j);
                }
                else if( payoff == maxPayoff){
                    maxIdxs.push_back(j);
                }
                
            }
        }
        for(auto it:maxIdxs){
            G[i][it]=G[it][i]=1; //0-no edge 1-unpaired 2-paired
        }
    }
    // cout<<"Preferred sellers graph updated!"<<endl;
}

/** Main logic for the market-clearing algorithm
 * params:  
 *          buyer_excluded: idx of the buyer excluded for VCG computing, default set to -1 (the buyer_seller pair is excluded, this is for computing V^(I)_(B-j))
 *          except: idx of the buyer excluded for computing the total buyer valuation, this is for computing V^(I-i)_(B-j), default set to -1
 * return  vector of {welfare, welfare_excluded} the second return is the total valuation except for the buyer_excluded i.e. V^(I-i)_(B-j)
 * */
int Matching_market::getMarketClearingPrices(int buyer_excluded, int except){
    int cnt=0;
    init(buyer_excluded);
    //showPlayers();
    while(1){
        cout<<">>> ------ Round "<<cnt<<" ------<<<"<<endl;
         //show updated prices
        showPrices();

        getPreferredSellers();
        //showG();
        vector<int> constricted;

        if(isPerfectMatching(constricted)){
            printf("Congratulations! You found the market clearing prices in %d steps.\n",cnt+1);
            return getResult(except);
            // return (except==-1)?getTotalValuation():getTotalValuationExceptBuyer(except);
        }
        else{
            //no augmenting path, cannot add more pairs
            //obtain a constricted set from the odd nodes (buyers)  

            printf("No perfect matching found, ");
            cout<<"Updated constricted:";
            for(int i=0;i<constricted.size();i++){
                cout<<" "<<constricted[i];
            }
            cout<<endl;
            sellerRaisePrices(constricted);   //raise their prices by 1
            offsetPrices();    //offset to 0
           
        }
        cnt++;
    }
}
/** func: compute VCG prices for the market based on two round of finding market-clearing prices
 * */
vector<int> Matching_market::getVCGPrices(){
    vector<int> VCG;
    for (int i=1;i<num_buyer*2;i+=2){ //for each buyer
        cout<<">>> ====================Acquiring VCG price for buyer #"<<(i-1)/2<<"===================== <<<"<<endl;
        //VCG = V^I_(B-j) - V^(I-i)_(B-j)
        //todo different modes for the pricing fuction:
        cout<<">>>1. Computing maximum social valuation in absence of buyer j"<<endl;
        int term1 = getMarketClearingPrices(i);//V^(I-i)_(B-j)
        cout<<">>>2. Computing maximum social valuation in absence of buyer j and the corresponding item"<<endl;
        int term2 = getMarketClearingPrices(-1, i); //V^(I)_(B-j)
        cout<<">>>3. Result: The VCG price for buyer #"<<(i-1)/2<<" is "<<term1-term2<<endl; //using parsed index for buyer, not raw
        VCG.push_back(term1-term2);
    }
    return VCG;
}