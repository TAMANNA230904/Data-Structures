// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. 
// It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

// Examples :
// Input: str1 = "heap", str2 = "pea"
// Output: 3
// Explanation: 2 deletions and 1 insertion.
// p and h deleted from heap. Then, p is inserted at the beginning.
// One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. 
// Thus, p contributes one to the deletion_count and one to the insertion_count.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.size();
	    int m=str2.size();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(str1[i-1]==str2[j-1]){
	            dp[i][j]=1+dp[i-1][j-1];
	            }
	            else
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    int maxSubstring=dp[n][m];
	    int deletions=n-maxSubstring;
	    int insertion=m-maxSubstring;
	    return deletions+insertion;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
