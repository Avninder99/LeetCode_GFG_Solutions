//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
//   private:
    void dfs(vector<vector<char>>&g, int r, int c, int &R, int &C){
        for(int i=-1; i<2; i++){
            for(int j=-1; j<2; j++){
                int tr = r + j, tc = c + i;
                if(tr >= 0 && tc >= 0 && tr < R && tc < C && g[tc][tr] == '1'){
                    g[tc][tr] = '0';
                    dfs(g, tr, tc, R, C);
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& g) {
        // Code here
        int count = 0, R = g[0].size(), C = g.size();
        for(int i=0; i<C; i++){
            for(int j=0; j<R; j++){
                if(g[i][j] == '1'){
                    count++;
                    g[i][j] = '0';
                    dfs(g, j, i, R, C);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends