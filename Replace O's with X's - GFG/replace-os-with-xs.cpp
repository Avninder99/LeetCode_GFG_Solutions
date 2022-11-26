//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>&mat, int r, int c, int &rs, int&cs, vector<vector<int>>&dir){
        mat[c][r] = 'A';
        for(int i=0;i<4;i++){
            int tr = r + dir[i][0], tc = c + dir[i][1];
            if(tr >= 0 && tc >= 0 && tr < rs && tc < cs && mat[tc][tr] == 'O'){
                dfs(mat, tr, tc, rs, cs, dir);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int rs = mat[0].size(), cs = mat.size();
        
        vector<vector<int>>dir;
        dir.push_back({0, -1});
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({-1, 0});
        
        for(int i=0;i<rs;i++){
            if(mat[0][i] == 'O'){
                dfs(mat, i, 0, rs, cs, dir);
            }
            if(mat[cs - 1][i] == 'O'){
                dfs(mat, i, cs-1, rs, cs, dir);
            }
        }
        
        for(int j=0;j<cs;j++){
            if(mat[j][0] == 'O'){
                dfs(mat, 0, j, rs, cs, dir);
            }
            if(mat[j][rs-1] == 'O'){
                dfs(mat, rs-1, j, rs, cs, dir);
            }
        }
        
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }else if(mat[i][j] == 'A'){
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends