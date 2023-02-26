//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int n = V, count = 0;     // 1 based
        vector<int>rec(n + 1, -1);
        
        int marker = 1;
        for(int i=1;i<=n;i++){
            if(rec[i] == -1){
                dfs(i, adj, rec, marker);
                marker++;
            }
        }
        
        vector<vector<int>>groups(marker);
        for(int i=1;i<=n;i++){
            groups[rec[i]].push_back(i);
        }
        
        for(auto itr: groups){
            int sum = 0, size = itr.size();
            for(auto node: itr){
                sum += adj[node].size();
            }
            if(sum == size*(size - 1)){
                count++;
            }
        }
        
        return count - 1;
    }
private:
    void dfs(int curr, vector<vector<int>>&adj, vector<int>&rec, int &marker){
        rec[curr] = marker;
        for(int itr: adj[curr]){
            if(rec[itr] == -1){
                dfs(itr, adj, rec, marker);
            }
        }
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends