#You are given a number n, Return the count of total numbers from 1 to n containing 4 as a digit.


##Approach:Traverse all the numbers from 1 to n ,convert the each number into a string and then traverse that string to check if 4 is present or not;
##Time Commplexity-O(n) for loop from 1 to n and to_string function takes logn time complexity ,so overall T.C. becomes O(nlogn).

###Code:-
  
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int ans=0;
       for(int i=1;i<=n;i++){
           string s=to_string(i);
           for(auto it:s){
               if(it=='4'){
               ans++;
               break;
               }
           }
       } 
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends

