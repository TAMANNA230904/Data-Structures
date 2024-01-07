Given an array arr of size N and an element k. The task is to find the count of elements in the array that appear more than n/k times.

//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        int maxi=arr[0];
       for(int i=0;i<n;i++){
           maxi=max(arr[i],maxi);
       }
       int x=n/k;
       int ans=0;
       unordered_map<int,int> countarr;
       for(int i=0;i<n;i++){
           countarr[arr[i]]+=1;
           
       }
       for(auto i:countarr){
           if(i.second>x)
           ans++;
       }
    
     return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
