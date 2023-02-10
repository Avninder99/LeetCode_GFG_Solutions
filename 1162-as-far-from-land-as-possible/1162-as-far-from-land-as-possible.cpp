class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        vector<vector<int>>dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // up, right, down, left
        
        queue<pair<int, int>>q1;
        
        int cs = g.size(), rs = g[0].size(), dist = 1;
        
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g[i][j] == 1) q1.push({i, j});
            }
        }
        if(q1.empty() || q1.size() == cs * rs) return -1;
        q1.push({-1, -1});
        
        while(q1.size() > 1){
            pair<int, int>h = q1.front();
            q1.pop();
            if(h.first == -1){
                dist++;
                q1.push({-1, -1});
                continue;
            }
            for(int i=0;i<4;i++){
                int tc = h.first + dir[i][0], tr = h.second + dir[i][1];
                if(tc >= 0 && tr >= 0 && tc < cs && tr < rs && g[tc][tr] == 0){
                    g[tc][tr] = dist;
                    q1.push({tc, tr});
                }
            }
        }
        return dist - 1;
    }
};