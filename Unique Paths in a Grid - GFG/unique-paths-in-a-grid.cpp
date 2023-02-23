//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &g) {
        // code here
        int cs = n, rs = m;
        if(g[0][0] == 0 || g[cs - 1][rs - 1] == 0){
            return 0;
        }
        
        for(int i=cs-2;i>=0;i--){
            if(g[i][rs - 1] != 0){
                g[i][rs - 1] = g[i + 1][rs - 1];
            }
        }
        
        for(int i=rs-2;i>=0;i--){
            if(g[cs - 1][i] != 0){
                g[cs - 1][i] = g[cs - 1][i + 1];
            }
        }
        
        for(int i=cs-2;i>=0;i--){
            for(int j=rs-2;j>=0;j--){
                if(g[i][j] != 0){
                    g[i][j] = (g[i][j + 1] + g[i + 1][j])%1000000007;
                }
            }
        }
        
        return g[0][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends