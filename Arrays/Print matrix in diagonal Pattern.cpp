Given a square matrix mat[][] of n*n size, the task is to determine the diagonal pattern which is a linear arrangement of the elements of the matrix as depicted in the following example:

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:

    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
     int n=mat.size();
     vector<int> ans;
     int row=0,col=0;
     bool isUp=1;
     
     while(row<n && col<n){
         // if diagonal is upward
         if(isUp){
             while(row>0 && col<n-1){
                 ans.push_back(mat[row][col]);
                 row--;
                 col++;
             }
            ans.push_back(mat[row][col]);
            if(col==n-1){
                row++;
            }
            else
            col++;
            
         }
         else{
             while(col>0 && row<n-1){
                 ans.push_back(mat[row][col]);
                 row++;
                 col--;
             }
             ans.push_back(mat[row][col]);
             if(row==n-1)
             col++;
             else
             row++;
         }
         isUp=!isUp;
     }
    return ans; 
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends
