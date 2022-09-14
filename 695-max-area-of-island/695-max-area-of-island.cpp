class Solution {
public:
    int capture(int i, int j, int csize, int rsize, vector<vector<int>>&g){
        if(i < 0 || i >= csize || j < 0 || j >= rsize || g[i][j] == 0) return 0;
        g[i][j] = 0;
        int count=1;
        count += capture(i-1, j, csize, rsize, g);
        count += capture(i, j+1, csize, rsize, g);
        count += capture(i+1, j, csize, rsize, g);
        count += capture(i, j-1, csize, rsize, g);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int csize = g.size(), rsize = g[0].size(), maxarea = 0;
        for(int i=0;i<csize;i++){
            for(int j=0;j<rsize;j++){
                if(g[i][j] == 1){
                    maxarea = max(maxarea, capture(i, j, csize, rsize, g));
                }
            }
        }
        return maxarea;
    }
};