class Solution {
public:
    int profitableSchemes(int n, int mp, vector<int>& group, vector<int>& profit) {
        int sum = 0;
        for(auto itr: profit){
            sum += itr;
        }
        vector<vector<vector<int>>>dp(group.size() + 1, vector<vector<int>>(sum + 1, vector<int>(n + 1, -1)));
        return func(group.size(), 0, n, mp, group, profit, dp);
    }
    int func(int ind, int cp, int wl, int &mp, vector<int>&g, vector<int>&p, vector<vector<vector<int>>>&dp){
        if(ind == 0){
            if(cp >= mp){
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp[ind][cp][wl] == -1){
            int pi = 0, np = 0;
            if(g[ind - 1] <= wl){
                pi = func(ind - 1, cp + p[ind - 1], wl - g[ind - 1], mp, g, p, dp);
            }
            np = func(ind - 1, cp, wl, mp, g, p, dp);

            
            dp[ind][cp][wl] = (pi + np)%1000000007;
            
        }
        return dp[ind][cp][wl];
        
    }
};