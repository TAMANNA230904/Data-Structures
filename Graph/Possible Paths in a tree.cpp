Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. 
For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

Note: Path from A to B and B to A are considered to be the same.
Input: 
n = 3
edges {start, end, weight} = {{1, 2, 1}, {2, 3, 4}}
q = 1
queries[] = {3}
Output: 
1
Explanation:
Query 1: Path from 1 to 2





  //{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int ans;
    vector<int> parent;
    vector<int> rank;
    
	public:
	int find(int x){
	    if(parent[x]==x)
	    return x;
	    
	 return  parent[x]=find(parent[x]);
	}
	static bool cmp(vector<int> &a,vector<int> &b){
	    return a[2]<b[2];
	}
	int Union(int u,int v){
	    u=find(u);
	    v=find(v);
	    if(rank[u]<rank[v]){
	        ans+=rank[u]*rank[v];
	        parent[u]=v;
	        rank[v]+=rank[u];
	       
	    }
	    else if(rank[u]>rank[v]){
	        ans+=rank[u]*rank[v];
	        parent[v]=u;
	        rank[u]+=rank[v];
	    }
	    else{
	         ans+=rank[u]*rank[v];
	         parent[u]=v;
	         rank[v]+=rank[u];
	    }
	    return ans;
	}
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    parent.resize(n+1);
	    rank.resize(n+1);
	    ans=0;
	    for(int i=0;i<=n;i++){
	    parent[i]=i;
	    rank[i]=1;
	    }
	    
	    vector<int> res;
	    map<int,int> mp;
	    sort(edges.begin(),edges.end(),cmp);
	    for(int i=0;i<n-1;i++){
	        mp[edges[i][2]]=Union(edges[i][0],edges[i][1]);
	    }
	    
	    
	    for(int query:queries){
	        int maxWeight=0;
	        for(auto i:mp){
	            if(i.first<=query)
	            maxWeight=max(maxWeight,i.second);
	            else
	            break;
	        }
	        res.push_back(maxWeight);
	    }
	    return res;;
	}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends
