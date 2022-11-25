class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&g) {
        // Tabulation Approach
        int rs = g[0].size(), cs = g.size(), step = 1;
	    vector<vector<int>>res(cs, vector<int>(rs, 100000));
        
        if(g[cs-1][rs-1] == 0)
            res[cs-1][rs-1] = 0;
        
        for(int i=cs-2;i>=0;i--){
            res[i][rs-1] = (g[i][rs-1] == 0) ? 0 : res[i+1][rs-1]+1;
        }
        
        for(int i=rs-2;i>=0;i--){
            res[cs-1][i] = (g[cs-1][i] == 0) ? 0 : res[cs-1][i+1]+1;
        }
        
        for(int i=cs-2;i>=0;i--){
            for(int j=rs-2;j>=0;j--){
                res[i][j] = (g[i][j] == 0) ? 0 : (min(res[i+1][j], res[i][j+1]) + 1);
            }
        }
        
        for(int i=1;i<rs;i++){
            res[0][i] = (g[0][i] == 0) ? 0 : min(res[0][i-1]+1, res[0][i]);
        }
        
        for(int i=1;i<cs;i++){
            res[i][0] = (g[i][0] == 0) ? 0 : min(res[i-1][0]+1, res[i][0]);
        }
        
        for(int i=1;i<cs;i++){
            for(int j=1;j<rs;j++){
                res[i][j] = (g[i][j] == 0) ? 0 : min((min(res[i-1][j], res[i][j-1]) + 1), res[i][j]);
            }
        }
        
        return res;
    }
};