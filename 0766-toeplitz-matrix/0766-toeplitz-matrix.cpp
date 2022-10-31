class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int rs = m[0].size(), cs = m.size(), holder, r, c;
        for(int i=0;i<rs;i++){
            c = 0, r = i;
            holder = m[c][r];
            while(r < rs && c < cs) if(m[c++][r++] != holder) return false;
        }
        for(int i=0;i<cs;i++){
            r = 0, c = i;
            holder = m[c][r];
            while(r < rs && c < cs) if(m[c++][r++] != holder) return false;
        }
        return true;
    }
};