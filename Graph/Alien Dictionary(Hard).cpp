Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function
is correct else 0 denoting incorrect string returned.


// Input:  N = 5, K = 4, dict = {"baa","abcd","abca","cab","cad"}
// Output: 1

  
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string topoSort(int N,int K,unordered_map<char,list<char>> &mp){
        vector<int> indegree(K,0);
        for(auto i:mp){
            for(auto j:i.second){
                indegree[j-'a']++;
            }
        }
        
        queue<char> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(char(97+i));
            }
        }
        string ans;
        while(!q.empty()){
            char ch=q.front();
            q.pop();
            ans.push_back(ch);
            for(auto nei:mp[ch]){
                indegree[nei-'a']--;
                if(indegree[nei-'a']==0)
                q.push(nei);
            }
        }
        return ans;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char,list<char>> mp;
        
        
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int k=0;
            while(k<s1.length() && k<s2.length()){
                if(s1[k]!=s2[k]){
                    mp[s1[k]].push_back(s2[k]);
                    break;
                }
                k++;
            }
            
        }
        
     
        string ans=topoSort(N,K,mp);
        return ans;
      
    }
};



//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
