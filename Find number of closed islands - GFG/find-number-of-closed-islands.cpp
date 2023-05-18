//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& m, int N, int M) {
        // Code here
        int cs = m.size(), rs = m[0].size();
        vector<vector<int>>dirc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i=0;i<rs;i++){
            if(m[0][i] == 1){
                m[0][i] = 0;
                dfs(0, i, dirc, m, cs, rs);
            }
            if(m[cs - 1][i] == 1){
                m[cs - 1][i] = 0;
                dfs(cs - 1, i, dirc, m, cs, rs);
            }
        }
        for(int i=0;i<cs;i++){
            if(m[i][0] == 1){
                m[i][0] = 0;
                dfs(i, 0, dirc, m, cs, rs);
            }
            if(m[i][rs - 1] == 1){
                m[i][rs - 1] = 0;
                dfs(i, rs - 1, dirc, m, cs, rs);
            }
        }
        int count = 0;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j] == 1){
                    count++;
                    dfs(i, j, dirc, m, cs, rs);
                }
            }
        }
        return count;
    }
    void dfs(int c, int r, vector<vector<int>>&dirc, vector<vector<int>>&m, int &cs, int &rs){
        for(int k=0;k<4;k++){
            int nc = c + dirc[k][0], nr = r + dirc[k][1];
            if(nc < 0 || nr < 0 || nc >= cs || nr >= rs || m[nc][nr] == 0){
                continue;
            }
            m[nc][nr] = 0;
            dfs(nc, nr, dirc, m, cs, rs);
        }
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends