class Solution {
public:
    void func(vector<vector<int>>&i, int r, int c, int icr, int fcr, int rs, int cs){
        if(r < 0 || c < 0 || r >= rs || c >= cs || i[c][r] != icr) return;
        i[c][r] = fcr;
        func(i,r,c-1,icr,fcr,rs,cs);
        func(i,r+1,c,icr,fcr,rs,cs);
        func(i,r,c+1,icr,fcr,rs,cs);
        func(i,r-1,c,icr,fcr,rs,cs);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& i, int sr, int sc, int fcr) {
        int rsize = i[0].size(), csize = i.size(), icr = i[sr][sc];
        if(icr == fcr) return i;
        func(i, sc, sr, icr, fcr, rsize, csize);
        return i;
    }
};