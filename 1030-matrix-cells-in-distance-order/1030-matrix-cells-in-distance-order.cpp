class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int r, int c, int rc, int cc) {
        vector<vector<int>>rec(r, vector<int>(c, 0)), dirc = {{-1,0},{0,1},{1,0},{0,-1}}, res;
        queue<pair<int, int>>q1;
        q1.push({rc, cc});
        rec[rc][cc] = 1;
        while(!q1.empty()){
            pair<int, int>h = q1.front();
            q1.pop();
            res.push_back({h.first, h.second});
            for(auto itr: dirc){
                int rt = h.first + itr[0], ct = h.second + itr[1];
                if(rt < 0 || ct < 0 || rt >= r || ct >= c || rec[rt][ct] == 1) continue;
                q1.push({rt, ct});
                rec[rt][ct] = 1;
            }
        }
        return res;
    }
};