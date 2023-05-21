class Solution {
public:
    int shortestBridge(vector<vector<int>>& g) {
        vector<vector<int>>dirc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int f = 2, n = g.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j] == 1){
                    g[i][j] = f;
                    dfs(i, j, g, f, n, n, dirc);
                    f++;
                }
            }
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        // dist, c, r
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j] == 2){
                    pq.push({0, i, j});
                }
            }
        }
        
        // vector<vector<int>>vis(n, vector<int>(n, 0));
        while(!pq.empty()){
            vector<int>h = pq.top();
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nc = h[1] + dirc[i][0], nr = h[2] + dirc[i][1];
                if(nc < 0 || nc >= n || nr < 0 || nr >= n || g[nc][nr] == 2){
                    continue;
                }
                if(g[nc][nr] == 3){
                    return h[0];
                }
                g[nc][nr] = 2;
                pq.push({h[0] + 1, nc, nr});
            }
        }
        return 0;
    }
    void dfs(int c, int r, vector<vector<int>>&g, int &flag, int &cs, int &rs, vector<vector<int>>&dirc){
        for(int i=0;i<4;i++){
            int nc = c + dirc[i][0], nr = r + dirc[i][1];
            if(nc < 0 || nc >= cs || nr < 0 || nr >= rs || g[nc][nr] != 1){
                continue;
            }
            g[nc][nr] = flag;
            dfs(nc, nr, g, flag, cs, rs, dirc);
        }
    }
};