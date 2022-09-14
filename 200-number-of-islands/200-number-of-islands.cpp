class Solution {
public:
    void capture(int i, int j, int csize, int rsize, vector<vector<char>>&g){
        if(i < 0 || i >= csize || j < 0 || j >= rsize || g[i][j] == '0') return;
        g[i][j] = '0';
        capture(i-1, j, csize, rsize, g);
        capture(i, j+1, csize, rsize, g);
        capture(i+1, j, csize, rsize, g);
        capture(i, j-1, csize, rsize, g);
        return;
    }
    int numIslands(vector<vector<char>>& g) {
        int csize = g.size(), rsize = g[0].size(), counter = 0;
        for(int i=0;i<csize;i++){
            for(int j=0;j<rsize;j++){
                if(g[i][j] == '1'){
                    counter++;
                    capture(i, j, csize, rsize, g);
                }
            }
        }
        return counter;
    }
};