class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& g) {
        int rs = g[0].size(), cs = g.size();
        vector<vector<int>>dp(cs, vector<int>(rs, 0));
        
        traverser(0, 0, rs, cs, g, dp);
        
        vector<int> d(cs + rs - 1);
        for(int i=0; i<cs; i++){
            for(int j=0; j<rs; j++){
                if(dp[i][j] == 1) d[i + j]++;
            }
        }
        
        for(int i=1; i<(cs + rs - 2); i++){ 
            if(d[i] < 2) return true;
        }
        
        return false;
    }
private:
    int traverser(int r, int c, int &rs, int &cs, vector<vector<int>>&g, vector<vector<int>>&dp){
        if(r == rs-1 && c == cs-1){
            return 1;
        }
        if(dp[c][r] == 1) return 1;
        
        int right = 0, down = 0;
        if(r+1 < rs && g[c][r+1] == 1){
            right = traverser(r+1, c, rs, cs, g, dp);
        }
        if(c+1 < cs && g[c+1][r] == 1){
            down = traverser(r, c+1, rs, cs, g, dp);
        }
        dp[c][r] = right || down;
        
        return dp[c][r];
    }
};