Given a array, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
Keep the following points in mind:

If x is present in the array, then it need not be considered.
If two elements have the same difference as x, the greater element is prioritized.
If sufficient elements are not present on the right side, take elements from the left and vice versa.


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int find(vector<int> arr,int low,int high,int x){
      if(arr[high]<=x) return high;
      if(arr[low]>x) return low;
      
      int  mid=(low+high)/2;
      if(arr[mid]<=x && arr[mid+1]>x) return mid;
      else if(arr[mid]<x)
      return find(arr,mid+1,high,x);
      else
      return find(arr,low,mid-1,x);
  }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
    int id1=find(arr,0,n-1,x);
    int id2=id1+1;
    if(arr[id1]==x)
    id1--;
    
    vector<int> ans;
    while(k>0){
    if(id1>=0 && id2<n){
       if(abs(arr[id1]-x)<abs(arr[id2]-x))
       {ans.push_back(arr[id1]);
       k--;
        id1--;
       }
       else{
         ans.push_back(arr[id2]);
         k--;
         id2++;  
       }
    }
    
    else if(id1>=0){
        ans.push_back(arr[id1]);
        k--;
        id1--;
    }
    else{
         ans.push_back(arr[id2]);
         k--;
         id2++;  
    }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
