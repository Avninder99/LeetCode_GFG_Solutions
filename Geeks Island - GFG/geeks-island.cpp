//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int water_flow(vector<vector<int>> &g,int N,int M){
    // Write your code here.
        int cs = g.size(), rs = g[0].size(), res = 0;
        vector<vector<int>>records(cs, vector<int>(rs, 0)), dirc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Indian -> 1, Arabian -> 10
        
        // Indian left
        for(int i=0;i<cs;i++){
            if(records[i][0] == 0){
                records[i][0] = 1;
                dfs(records[i][0], i, 0, g, records, dirc, 1, rs, cs);
            }
        }
        
        // Indian up
        for(int i=0;i<rs;i++){
            if(records[0][i] == 0){
                records[0][i] = 1;
                dfs(records[0][i], 0, i, g, records, dirc, 1, rs, cs);
            }
        }
        
        
        // Arabian right
        for(int i=0;i<cs;i++){
            if(records[i][rs - 1] < 10){
                records[i][rs - 1] += 10;
                dfs(records[i][rs - 1], i, rs - 1, g, records, dirc, 10, rs, cs);
            }
        }
        
        // Arabian down
        for(int i=0;i<rs;i++){
            if(records[cs - 1][i] < 10){
                records[cs - 1][i] += 10;
                dfs(records[cs - 1][i], cs - 1, i, g, records, dirc, 10, rs, cs);
            }
        }
        
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(records[i][j] == 11){
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(int val, int c, int r, vector<vector<int>>&g, vector<vector<int>>&records, vector<vector<int>>&dirc, int flag, int &rs, int &cs){
        for(auto itr: dirc){
            int nr = r + itr[1], nc = c + itr[0];
            if(nr < 0 || nc < 0 || nr >= rs || nc >= cs || g[nc][nr] < g[c][r] || records[nc][nr] >= flag){
                continue;
            }
            records[nc][nr] += flag;
            dfs(g[nc][nr], nc, nr, g, records, dirc, flag, rs, cs);
        }
        return;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends