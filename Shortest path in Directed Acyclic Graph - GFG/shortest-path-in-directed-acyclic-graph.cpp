//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& e){
        // code here
        vector<int>distRec(N, INT_MAX), vis(N, 0);
        distRec[0] = 0;
        
        vector<vector<int>>adj(N, vector<int>(N, -1));
        
        for(auto itr: e){
            adj[itr[0]][itr[1]] = itr[2];
        }
        
        queue<int>q1;
        q1.push(0);
        
        while(!q1.empty()){
            int holder = q1.front();
            q1.pop();
            
            for(int i=0;i<N;i++){
                if(adj[holder][i] >= 0){
                    int t = distRec[holder] + adj[holder][i];
                    if(t < distRec[i])
                    distRec[i] = t;
                    q1.push(i);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(distRec[i] == INT_MAX){
                distRec[i] = -1;
            }
        }
        
        return distRec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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