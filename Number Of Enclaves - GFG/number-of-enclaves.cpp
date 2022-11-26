//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&g, int r, int c, int &rs, int&cs, vector<vector<int>>&dir){
        g[c][r] = 2;
        for(int i=0;i<4;i++){
            int tr = r + dir[i][0], tc = c + dir[i][1];
            if(tr >= 0 && tc >= 0 && tr < rs && tc < cs && g[tc][tr] == 1){
                dfs(g, tr, tc, rs, cs, dir);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &g) {
        // Code here
        int rs = g[0].size(), cs = g.size();
        
        vector<vector<int>>dir;
        dir.push_back({0, -1});
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({-1, 0});
        
        for(int i=0;i<rs;i++){
            if(g[0][i] == 1){
                dfs(g, i, 0, rs, cs, dir);
            }
            if(g[cs - 1][i] == 1){
                dfs(g, i, cs-1, rs, cs, dir);
            }
        }
        
        for(int j=0;j<cs;j++){
            if(g[j][0] == 1){
                dfs(g, 0, j, rs, cs, dir);
            }
            if(g[j][rs-1] == 1){
                dfs(g, rs-1, j, rs, cs, dir);
            }
        }
        
        int count = 0;
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends