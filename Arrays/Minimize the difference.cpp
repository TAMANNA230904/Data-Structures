You are given an array arr of size n. You have to remove a subarray of size k , such that the difference between the maximum and minimum values
of the remaining array is minimized.
Find the minimum value obtained after performing the operation of the removal of the subarray and return it.

//Use of Sliding Window and Kadane's Algorithm
  //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
       
        int rmax[n];
        rmax[n-1]=arr[n-1];
        int rmin[n];
        rmin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(arr[i],rmax[i+1]);
            rmin[i]=min(arr[i],rmin[i+1]);
        }
       int ans=rmax[k]-rmin[k];
       int lmax=arr[0],lmin=arr[0];
       
       for(int i=1;i<n-k;i++){
           int Remmax=max(lmax,rmax[i+k]);
           int Remmin=min(lmin,rmin[i+k]);
           int currDiff=Remmax-Remmin;
           ans=min(ans,currDiff);
           
           lmax=max(arr[i],lmax);
           lmin=min(arr[i],lmin);
       }
    ans=min(ans,lmax-lmin);
    return ans;
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

