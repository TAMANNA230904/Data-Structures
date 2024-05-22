We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations
array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d.
Find the answer exactly to 2 decimal places.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(double mid,vector<int> &arr, int k){
      int n=arr.size();
      int count=0;
      for(int i=1;i<n;i++){
          int dist=arr[i]-arr[i-1];
          if(dist<=mid)
          continue;
          else{
             count+=dist/mid; 
          }
      }
      if(count<=k)
      return true;
      
      return false;
  }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        double low=0.0;
        double high=0.0;
        for(int i=1;i<n;i++){
          if(high<stations[i]-stations[i-1]){
              high=stations[i]-stations[i-1];
          }
        }
        double ans=high;
        while(high-low>1e-9){
            double mid=(high+low)/2.0;
            if(check(mid,stations,k)){
                high=mid;
                ans=mid;
            }
            else{
                low=mid;
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
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends

