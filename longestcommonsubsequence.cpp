#include<iostream>
using namespace std;
int lcs(string s1,string s2,int n,int m){
    int arr[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                arr[i][j]=0;
            }
            else{
                if(s1[i-1]==s2[j-1]){
                    arr[i][j]=1+max(arr[i-1][j],arr[i][j-1]);
                }
                else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
    }
    return arr[n][m];
}
int main(){
    string s1="abcdef";
    string s2="bde";
int n=s1.length();
int m=s2.length();
int ans=lcs(s1,s2,n,m);
cout<<"Longest common subsequence is of size:"<<ans<<endl;
return 0;
}