//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& e) {
        // Code here
        
        vector<vector<pair<int, int>>>adj(n+1); // to, weight
        vector<vector<int>>rec(n+1,  vector<int>(2, -1)); // distance, prev
        vector<int>res;
        
        for(int i=0;i<=n;i++){
            rec[i][0] = 1e7;
        }
        
        for(auto itr: e){
            adj[itr[0]].push_back({itr[1], itr[2]});
            adj[itr[1]].push_back({itr[0], itr[2]});
        }
        
        rec[1][0] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // cost, curr_node
        pq.push({0, 1});
        
        while(!pq.empty()){
            pair<int, int>h = pq.top();
            pq.pop();
            
            for(auto itr: adj[h.second]){
                int t = h.first + itr.second;
                if(t < rec[itr.first][0]){
                    pq.push({t, itr.first});
                    rec[itr.first][0] = t;
                    rec[itr.first][1] = h.second;
                }
            }
        }
        if(rec[n][1] == -1){
            res.push_back(-1);
            return res;
        }
        int currentNode = n;
        while(currentNode != -1){
            res.push_back(currentNode);
            currentNode = rec[currentNode][1];
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends