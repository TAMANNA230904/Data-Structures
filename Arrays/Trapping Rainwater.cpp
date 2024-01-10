Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks
during the rainy season. 

  //{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       long long ans=0;
       long long  l=0,r=n-1,leftmax=0,rightmax=0;
       while(l<=r){
           if(arr[l]<=arr[r]){
               if(arr[l]>=leftmax)
               leftmax=arr[l];
               else{
                   ans+=leftmax-arr[l];
               }
               l++;
           }
           
           else{
               if(arr[r]>=rightmax)
               rightmax=arr[r];
               else{
                   ans+=rightmax-arr[r];
               }
                r--;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
