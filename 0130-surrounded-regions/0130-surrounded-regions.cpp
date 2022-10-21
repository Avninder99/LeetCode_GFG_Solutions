class Solution {
public:
    void changer(vector<vector<char>>&b, int c, int r, vector<vector<int>>&d, int cs, int rs){
        if(c < 0 || r < 0 || c >= cs || r >= rs || b[c][r] != 'O') return;
        if(b[c][r] == 'O') b[c][r] = 'S';
        for(int i=0;i<4;i++){
            changer(b, c+d[i][0], r+d[i][1], d, cs, rs);
        }
        return;
    }
    void solve(vector<vector<char>>& b) {
        int cs = b.size(), rs = b[0].size();
        vector<vector<int>>d;
        d.push_back({-1,0});
        d.push_back({0,1});
        d.push_back({1,0});
        d.push_back({0,-1});
        for(int i=0;i<rs;i++){
            if(b[0][i] == 'O') changer(b, 0, i, d, cs, rs);
            if(b[cs-1][i] == 'O') changer(b, cs-1, i, d, cs, rs);
        }
        for(int i=0;i<cs;i++){
            if(b[i][0] == 'O') changer(b, i, 0, d, cs, rs);
            if(b[i][rs-1] == 'O') changer(b, i, rs-1, d, cs, rs);
        }
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(b[i][j] == 'O') b[i][j] = 'X';
                else if(b[i][j] == 'S') b[i][j] = 'O';
            }
        }
        return;
    }
};