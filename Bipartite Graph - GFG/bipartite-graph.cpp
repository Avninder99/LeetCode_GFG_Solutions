//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int curr, vector<int>adj[], int col, vector<int>&rec){
        rec[curr] = col;
        col = ++col%2;
        for(int itr: adj[curr]){
            if(rec[itr] == rec[curr]){
                return false;
            }else if(rec[itr] == -1){
                if(!dfs(itr, adj, col, rec)){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>rec(V, -1);
	    for(int i=0;i<V;i++){
	        if(rec[i] == -1){
	            if(!dfs(i, adj, 0, rec)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends