Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. 
If such a subarray do not exist return 0 in that case.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
    //   int ans=INT_MAX;
    //   for(int i=0;i<n;i++){
    //       int sum=0;
    //       for(int j=i;j<n;j++){
    //           sum+=arr[j];
    //           if(sum>x){
    //               ans=min(ans,j-i+1);
    //               break;
    //           }
    //       }
    //   }
    //   if(ans!=INT_MAX)
    //   return ans;
    
    //   return 0;
    int curr_sum=0;
    int ans=INT_MAX;
    int s=0,e=0;
    while(e<n){
        
        while(curr_sum<=x && e<n){
        curr_sum+=arr[e];
        e++;
    }
    
        while(curr_sum>x && s<n){
            ans=min(ans,e-s);
        curr_sum-=arr[s];
        s++;
       }
    }
      if(ans!=INT_MAX)
      return ans;
    
      return 0;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends
