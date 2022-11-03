class Solution {
public:
    void func(int c, int r, vector<vector<int>>&g2, vector<vector<int>>&d, int &rs, int &cs){
        g2[c][r] = 0;
        for(int i=0;i<4;i++){
            if(r+d[i][0] < 0 || r+d[i][0] >= rs || c+d[i][1] < 0 || c+d[i][1] >= cs || g2[c+d[i][1]][r+d[i][0]] != 1) continue;
            func(c+d[i][1], r+d[i][0], g2, d, rs, cs);
        }
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int rs = g1[0].size(), cs = g1.size(), counter=0;
        vector<vector<int>>d;
        d.push_back({0,-1});
        d.push_back({1,0});
        d.push_back({0,1});
        d.push_back({-1,0});
        // convert all 1 islands on g2 which have even one 0 for it's land cells to 0
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g2[i][j] == 1 && g1[i][j] == 0) func(i, j, g2, d, rs, cs);
            }
        }
        // count the number of sub islands in g2 and convert their 1 cells to 0
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g2[i][j] == 1){
                    counter++;
                    func(i, j, g2, d, rs, cs);
                }
            }
        }
        return counter;
    }
};