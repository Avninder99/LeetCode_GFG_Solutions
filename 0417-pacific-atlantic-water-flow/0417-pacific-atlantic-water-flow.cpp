class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int cs = h.size(), rs = h[0].size();
        vector<vector<int>>records(cs, vector<int>(rs, 0)), dirc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, res;
        
        // Pacific -> 1, Atlantic -> 10
        
        // Pacific left
        for(int i=0;i<cs;i++){
            if(records[i][0] == 0){
                records[i][0] = 1;
                dfs(i, 0, h, records, dirc, 1, rs, cs);
            }
        }
        
        // Pacific up
        for(int i=0;i<rs;i++){
            if(records[0][i] == 0){
                records[0][i] = 1;
                dfs(0, i, h, records, dirc, 1, rs, cs);
            }
        }
        
        
        // Atlantic right
        for(int i=0;i<cs;i++){
            if(records[i][rs - 1] < 10){
                records[i][rs - 1] += 10;
                dfs(i, rs - 1, h, records, dirc, 10, rs, cs);
            }
        }
        
        // Atlantic down
        for(int i=0;i<rs;i++){
            if(records[cs - 1][i] < 10){
                records[cs - 1][i] += 10;
                dfs(cs - 1, i, h, records, dirc, 10, rs, cs);
            }
        }
        
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(records[i][j] == 11){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    void dfs(int c, int r, vector<vector<int>>&h, vector<vector<int>>&records, vector<vector<int>>&dirc, int flag, int &rs, int &cs){
        for(auto itr: dirc){
            int nr = r + itr[1], nc = c + itr[0];
            if(nr < 0 || nc < 0 || nr >= rs || nc >= cs || h[nc][nr] < h[c][r] || records[nc][nr] >= flag){
                continue;
            }
            records[nc][nr] += flag;
            dfs(nc, nr, h, records, dirc, flag, rs, cs);
        }
        return;
    }
};