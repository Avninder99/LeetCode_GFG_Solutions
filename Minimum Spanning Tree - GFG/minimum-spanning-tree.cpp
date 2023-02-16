//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>visited(V, 0);
        // 0 -> not visited yet, 1 -> visited
        
        int res = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        // [ edge weight, current node, parent node ]
        
        pq.push({0, 0, -1});
        
        while(!pq.empty()){
            vector<int>holder = pq.top();
            pq.pop();
            
            if(visited[holder[1]]){
                continue;
            }
            visited[holder[1]] = 1;
            
            for(auto itr: adj[holder[1]]){
                if(visited[itr[0]] == 0){
                    pq.push({itr[1], itr[0], holder[1]});
                }
            }
            
            if(holder[2] > -1){
                res += holder[0];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends