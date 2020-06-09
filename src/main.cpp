#include<iostream>
#include<matching_market.h>
using namespace std;



int main(){
    int t;cin>>t;
    Matching_market s(t);
    s.inputValuation();
    vector<int> res = s.getVCGPrices();
    cout<<"Final VCG prices:"<<endl;
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
    char x;cin>>x;
    return 0;
}