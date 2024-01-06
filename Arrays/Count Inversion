Problem statement
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:
1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'
Where 'i' and 'j' denote the indices ranging from [0, 'N').




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   long long int merge(long long *arr,long long N,long long low ,long long high){
        long long int cnt=0;
      long long mid=low+(high-low)/2;
      long long n1=mid-low+1;
      long long n2=high-mid;
      vector<long long> first(n1);
      vector<long long> second(n2);
      for(int i=0;i<n1;i++){
          first[i]=arr[i+low];
      }
      for(int i=0;i<n2;i++){
          second[i]=arr[i+mid+1];
      }
     long long left=0,right=0,k=low;
      while(left<n1 && right<n2 ){
          if(first[left]<=second[right]){
              arr[k]=first[left];
              left++;
              k++;
          }
          else{
              cnt+=n1-left;
              arr[k]=second[right];
              k++;right++;
          }
      }
      while(left<n1){
          arr[k]=first[left];
          k++;left++;
      }
      while(right<n2){
          arr[k]=second[right];
          k++;right++;
      }
      return cnt;
    }
    long long int mergesort(long long *arr,long long N,long long low ,long long high){
        long long int ans=0;
        if(low>=high) return ans;
        long long mid=low+(high-low)/2; 
       ans+=mergesort(arr,N,low,mid);
       ans+=mergesort(arr,N,mid+1,high);
        ans+=merge(arr,N,low,high);
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr,N,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
