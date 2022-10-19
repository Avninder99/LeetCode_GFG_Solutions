class Solution {
public:
    bool func1(vector<vector<char>>&b, string &w, int ptr, int c, int r, vector<vector<int>>&d, int &rs, int &cs){
        if(ptr >= w.size()) return true;
        if(c < 0 || r < 0 || c >= cs || r >= rs || b[c][r] != w[ptr]) return false;
        char temp = b[c][r];
        bool found = false;
        b[c][r] = '1';
        for(int i=0;i<4;i++){
            found = func1(b, w, ptr+1, c+d[i][0], r+d[i][1], d, rs, cs);
            if(found) return true;
        }
        b[c][r] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int rs=b[0].size(), cs=b.size(), ptr=0;
        vector<vector<int>>d;
        d.push_back({-1,0});
        d.push_back({0,1});
        d.push_back({1,0});
        d.push_back({0,-1});
        bool temp = false;
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                temp = func1(b, w, 0, i, j, d, rs, cs);
                if(temp) return true;
            }
        }
        return false;
    }
};