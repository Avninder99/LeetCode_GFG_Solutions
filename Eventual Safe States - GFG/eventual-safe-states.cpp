//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool checker(int curr, vector<int>&rec, vector<int>&res, vector<int>adj[], int &col){
        // no loop - true
        // loop - false
        rec[curr] = col;
        bool safe = true;
        for(int itr: adj[curr]){
            if(rec[itr] == -9) continue;
            else if(rec[itr] == -10 || rec[itr] == col){
                safe = false;
            }
            else if(rec[itr] == -1){
                if(!checker(itr, rec, res, adj, col)){
                    safe = false;
                }
            }
        }
        if(safe){
            res.push_back(curr);
            rec[curr] = -9;
        }else{
            rec[curr] = -10;
        }
        return safe;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // -1 -> not visited
        // -9 -> visited and does not lead to a loop neither is a part of it
        // -10 -> leads to or is a part of a loop
        // 0 - v -> temp markers
        
        // at last i have to return the nodes that are marked with -9 (stored in res)
        vector<int>rec(V, -1), res;
        for(int i=0;i<V;i++){
            if(rec[i] == -1){
                checker(i, rec, res, adj, i);
            }
        }
        sort(res.begin(), res.end());
        return res;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends