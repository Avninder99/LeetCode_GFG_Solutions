//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indRec(V), res;
	    queue<int>q1;
	    for(int i=0;i<V;i++){
	        for(auto itr: adj[i]){
	            indRec[itr]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indRec[i] == 0){
	            q1.push(i);
	        }
	    }
	    while(!q1.empty()){
	        int holder = q1.front();
	        q1.pop();
	        for(auto itr: adj[holder]){
	            if(--indRec[itr] == 0){
	                q1.push(itr);
	            }
	        }
	        res.push_back(holder);
	    }
	    return res.size() < V;
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