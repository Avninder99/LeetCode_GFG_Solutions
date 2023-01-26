//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pr) 
    {
        //code here
        vector<vector<int>>adj(n);
        for(auto itr: pr){
            adj[itr[1]].push_back(itr[0]);
        }
        
	    vector<int>indRec(n), res;
	    queue<int>q1;
	    
	    for(int i=0;i<m;i++){
	        indRec[pr[i][0]]++;
	    }
	    
	    for(int i=0;i<n;i++){
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
	    
	    if(res.size() != n) res.clear();
	    return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends