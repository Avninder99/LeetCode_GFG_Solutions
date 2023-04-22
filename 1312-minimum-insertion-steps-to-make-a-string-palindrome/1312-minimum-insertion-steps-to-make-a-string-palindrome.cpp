class Solution {
public:
    int minInsertions(string s) {
        int l = 0, r = s.length() - 1;
        vector<vector<int>>dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        return func(s, l, r, dp);
    }
    int func(string &s, int l, int r, vector<vector<int>>&dp){
        if(l == r || (l == r - 1 && s[l] == s[r])){
            return 0;
        }
        if(dp[l][r] == -1){
            int lp = 0, rp = 0, np = 0;
            if(s[l] == s[r]){
                np = func(s, l + 1, r - 1, dp);
                dp[l][r] = np;
            }else{
                lp = 1 + func(s, l + 1, r, dp);
                rp = 1 + func(s, l, r - 1, dp);
                dp[l][r] = min(lp, rp);
            }
        }
        return dp[l][r];
    }
};