Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. 
Let the sum of the elements of these two subsets be S1 and S2. 
Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1
and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.


  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
  int solve(int idx, int b, vector<int>& arr,vector<vector<int>> &dp){
      if(idx==0){
          if(b==0)
          return 1;
          else
          return 0;
      }
      if(dp[idx][b]!=-1)
      return dp[idx][b];
      
      dp[idx][b]=solve(idx-1,b,arr,dp)%mod;
      
      if(arr[idx-1]<=b){
      dp[idx][b] +=solve(idx-1,b-arr[idx-1],arr,dp);
      dp[idx][b]%=mod;
      }
      return dp[idx][b];
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
        
        if(sum<d || (sum-d)%2==1)
        return 0;
        
        int b=(sum-d)/2;
       
        
       
       vector<vector<int>> dp(n+1,vector<int>(b+1,-1));
       
       return solve(n,b,arr,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends

