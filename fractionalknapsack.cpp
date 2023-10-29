#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &w,vector<int> &p,int P,int W){
    vector<int> r;
    int profit_final=0;
    for(int i=0;i<P;i++){
        r.push_back(p[i]/w[i]);
    }
   sort(r.begin(),r.end(),greater<int>());
   // incorrect logic r me sorted i hai and w or p me unsorted
   for(int i=0;i<P;i++){
    if(W>w[i]){
        profit_final+=p[i];
    }
    else{
        profit_final+=p[i]*W/w[i];
    }
    W-=w[i];
   }
return profit_final;
}
int main(){
int W,P;
cout<<"Enter capacity of knapsack and no. of products"<<endl;
cin>>W;
cin>>P;
vector<int> wi;
vector<int> pi;
for(int i=0;i<P;i++){
    int weight,profit;
    cout<<"Enter weight and profit of products"<<endl;
    cin>>weight;
    cin>>profit;
    wi.push_back(weight);
    pi.push_back(profit);
}
int ans=solve(wi,pi,P,W);
cout<<"Maximum profit of fractional knapsack="<<ans;   
    return 0;
}