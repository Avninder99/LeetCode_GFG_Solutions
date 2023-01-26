//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> oadj[]) {
        // code here
        // second approach using kahn's algorithms
        
        // reversed all the edges
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            for(auto itr: oadj[i]){
                adj[itr].push_back(i);
            }
        }
        
        // use kahn's algo starting from all the nodes with indegree 0
        // (these nodes were terminal nodes in the begining)
        
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
	    
	    // what is happening is thst kahn's algo pushes all the nodes from out zero indegree nodes
	    // whose indegree can be convertexd to zero
	    // what that means is the in original graph all edges from these nodes somehow leads to the terminal node
	    // without a loop inbetween
	    
	    // this is happening because kahn's algo remove all the edges from these nodes by reaching them from
	    // zero indegree nodes and these nodes become part of res when there indegree became zero
	    
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