//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int curr, vector<int>adj[], vector<int>&rec, int &col){     // return's true if cyclic
        rec[curr] = col;
        for(int itr: adj[curr]){
            if(rec[itr] == -9) continue;
            else if(rec[itr] == -1){
                if(dfs(itr, adj, rec, col)){
                    return true;
                }
            }else if(rec[itr] == col){
                return true;
            }
        }
        rec[curr] = -9;  // our marks that the node and further nodes are safe
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>rec(V, -1);
        for(int i=0;i<V;i++){
            if(rec[i] == -1){
                if(dfs(i, adj, rec, i)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends