class Solution {
public:
    void func(int c, int r, vector<vector<int>>&g, vector<vector<int>>&d, int &rs, int &cs){
        g[c][r] = 2;
        for(int i=0;i<4;i++){
            if(r+d[i][0] < 0 || r+d[i][0] >= rs || c+d[i][1] < 0 || c+d[i][1] >= cs || g[c+d[i][1]][r+d[i][0]] != 1) continue;
            func(c+d[i][1], r+d[i][0], g, d, rs, cs);
        }
    }
    int numEnclaves(vector<vector<int>>& g) {
        int rs = g[0].size(), cs = g.size();
        vector<vector<int>>d;
        d.push_back({0,-1});
        d.push_back({1,0});
        d.push_back({0,1});
        d.push_back({-1,0});
        for(int i=0;i<rs;i++){
            if(g[0][i] == 1) func(0, i, g, d, rs, cs);
            if(g[cs-1][i] == 1) func(cs-1, i, g, d, rs, cs);
        }
        for(int i=0;i<cs;i++){
            if(g[i][0] == 1) func(i, 0, g, d, rs, cs);
            if(g[i][rs-1] == 1) func(i, rs-1, g, d, rs, cs);
        }
        int counter=0;
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g[i][j] == 1) counter++;
            }
        }
        return counter;
    }
};