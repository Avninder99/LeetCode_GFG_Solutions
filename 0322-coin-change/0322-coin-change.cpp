class Solution {
public:
    int func(vector<int>&c, int suml, int size, int cu, vector<int>&dp){
        if(suml < 0) return 100000;
        if(suml == 0) return 0;
        int t1=100000, t2=100000;
        
        if(dp[suml] == -1){
            for(int i=size-1;i>=0;i--){
                if(suml - c[i] < 0) continue;
                t2 = func(c, suml-c[i], size, cu+1, dp);
                t1 = min(t1, t2);
            }
            dp[suml] = t1;
        }
        return dp[suml] + 1;
    }
    int coinChange(vector<int>& c, int a) {
        sort(c.begin(), c.end());
        int size = c.size();
        vector<int>dp(a+1, -1);
        int t = func(c, a, size, 0, dp);
        return t >= 100000 ? -1 : t;
    }
};