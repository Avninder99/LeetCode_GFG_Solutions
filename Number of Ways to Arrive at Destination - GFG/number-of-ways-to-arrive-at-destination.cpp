//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& r) {
        // code here
        vector<vector<pair<int, int>>>adj(n);   // from -> [ {to, travel_time}, ...]
        for(auto itr: r){
            adj[itr[0]].push_back({itr[1], itr[2]});
            adj[itr[1]].push_back({itr[0], itr[2]});
        }
        
        vector<vector<long long>>records(n);
        // records[i] => [
        //      0th index -> min time to reach this node,
        //      1st index -> how many incoming paths with min time
        // ]
        for(int i=0;i<n;i++){
            records[i] = {1000000009, 0};
        }
        records[0] = {0, 1};
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        // { time, current node }
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            pair<long long, int>holder = pq.top();
            pq.pop();
            int curr_node = holder.second;
            long long time_taken = holder.first;
            
            for(int i=0;i<adj[curr_node].size();i++){
                
                long long newTime = time_taken + adj[curr_node][i].second;
                int to_node = adj[curr_node][i].first;
                
                if(newTime < records[ to_node ][0]){
                    records[ to_node ] = {newTime, records[curr_node][1]};
                    pq.push({newTime, to_node});
                }
                else if(newTime == records[ to_node ][0]){
                    records[ to_node ][1] += records[curr_node][1];
                }
                
            }
        }
        
        return records[n - 1][1]%1000000007;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends