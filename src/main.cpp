#include<iostream>
#include<matching_market.h>
using namespace std;



int main(){
    int t;cin>>t;
    Matching_market s(t);
    s.inputValuation();

    //Computing Market Clearing Prices
    cout<<">>> Computing Market Clearing Prices ..."<<endl;
    s.getMarketClearingPrices(); 
    s.showPrices();
    //Computing VCG Prices based on the matchings found in Market Clearing Prices
    cout<<">>> Computing VCG Prices ..."<<endl;
    s.getVCGPrices();
    return 0;
}