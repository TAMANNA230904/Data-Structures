Given a string s of length n, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. Return the longest non-overlapping substring. Return "-1" if no such string exists.

Note: Multiple Answers are possible but you have to return the substring whose first occurrence is earlier.

For Example: "abhihiab", here both "ab" and "hi" are possible answers. But you will have to return "ab" because it's first occurrence appears
before the first occurrence of "hi".

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        int res_length=0;
        int idx=0;
        
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[i-1]==s[j-1] && dp[i-1][j-1]+1<=(j-i)){
                dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>res_length){
                        res_length=dp[i][j];
                        idx=i-1;
                    }
                }
            }
        }
        string res;
        if(res_length>0){
            for(int i=idx-res_length+1;i<=idx;i++)
            res.push_back(s[i]);
        }
        else
        res+="-1";
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
