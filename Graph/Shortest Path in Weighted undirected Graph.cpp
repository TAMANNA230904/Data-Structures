ou are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,
if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return
a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of 
the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

## SOLUTION:

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        int start =1;
        int target=n;
        unordered_map<int,list<pair<int,int>>> adjList;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
          adjList[u].push_back(make_pair(v,w));
          adjList[v].push_back(make_pair(u,w));
        }
        
        
       int dist[n+1];
       int parent[n+1];
       for(int i=0;i<=n;i++){
           dist[i]=INT_MAX;
           parent[i]=i;
       }
       
       set<pair<int,int>> st;
       dist[1]=0;
       st.insert(make_pair(0,1));
       while(!st.empty()){
           auto top=*(st.begin());
           int nodedist=top.first;
           int node=top.second;
           
           st.erase(st.begin());
           for(auto neighbour: adjList[node]){
               
               if(nodedist+neighbour.second<dist[neighbour.first]){
               auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
               if(record!=st.end())
               st.erase(record);
               
               dist[neighbour.first]=neighbour.second+nodedist;
               st.insert(make_pair(dist[neighbour.first],neighbour.first));
               parent[neighbour.first]=node;
               }
           }
           
       }
       
       
        vector<int> path;
        
        if(dist[n]==INT_MAX){
            path.push_back(-1);
            return path;
        }
        int i = n;
        while (i != 1) {
        path.push_back(i);
         i = parent[i];
         }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
       
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
