//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distT) {
        pair<int, int>res = {-1, 1e9};
        vector<vector<pair<int, int>>>adj(n);
        for(auto itr: edges){
            adj[itr[0]].push_back({itr[1], itr[2]});
            adj[itr[1]].push_back({itr[0], itr[2]});
        }
        // {distance, curr_node}
        
        for(int src=0;src<n;src++){
            vector<int>records(n, 1e9);
            records[src] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            
            pq.push({0, src});
            
            while(!pq.empty()){
                pair<int, int>holder = pq.top();
                pq.pop();
                
                if(holder.first > distT){
                    break;
                }
                
                for(auto itr: adj[holder.second]){
                    int toNode = itr.first, dist = itr.second;
                    if(holder.first + dist < records[toNode]){
                        records[toNode] = holder.first + dist;
                        pq.push({records[toNode], toNode});
                    }
                }
            }
            
            int count = 0;
            for(auto itr: records){
                if(itr > 0 && itr <= distT) count++;
            }
            if(count <= res.second){
                res = {src, count};
            }
        }
        return res.first;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends