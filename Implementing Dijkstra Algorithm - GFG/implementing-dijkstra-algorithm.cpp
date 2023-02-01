//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// struct comp(const pair<int, int>&a, const pair<int, int>%b){
//     return a.second < b.second;
// }

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        // cost, to
        
        vector<int>rec(V, INT_MAX);
        rec[S] = 0;
        
        pq.push(make_pair(S, 0));
        while(!pq.empty()){
            pair<int, int>t = pq.top();
            pq.pop();
            
            for(auto itr: adj[t.first]){
                if(itr[1] + t.second < rec[itr[0]]){
                    rec[itr[0]] = itr[1] + t.second;
                    pq.push({itr[0], rec[itr[0]]});
                }
            }
        }
        
        return rec;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends