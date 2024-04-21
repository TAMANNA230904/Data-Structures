There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
  The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional
  edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.


 class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)
        return true;

        unordered_map<int,list<int>> adjlist;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        stack<int> st;
        vector<bool> visited(n,0);
        st.push(source);
        visited[source]=1;
        while(!st.empty()){
           int topNode=st.top();
           st.pop();
           for(auto neighbor:adjlist[topNode])
             if(!visited[neighbor]){
                st.push(neighbor);
                visited[neighbor]=true;
                if(neighbor==destination)
                return true;
             }
        }
        return false;
    }
}; 

