//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& e, int N,int M, int src){
        // code here
        vector<int>res(N, -1), vis(N, 0);
        
        vector<vector<int>>adj(N);
        
        for(auto itr: e){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
        int dist = 0;
        queue<int>q1;
        q1.push(src);
        q1.push(-1);
        
        while(q1.size() > 1){
            int h = q1.front();
            q1.pop();
            
            if(h == -1){
                dist++;
                q1.push(-1);
                continue;
            }
            
            if(res[h] > -1) continue;
            
            res[h] = dist;
            for(auto itr: adj[h]){
                if(res[itr] == -1){
                    q1.push(itr);
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends