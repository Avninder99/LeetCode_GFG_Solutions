class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int l1 = t1.length(), l2 = t2.length();
        vector<vector<int>>dp(l1 + 1, vector<int>(l2 + 1, -1));
        return func(l1, l2, t1, t2, dp);
    }
    int func(int ind1, int ind2, string &t1, string &t2, vector<vector<int>>&dp){
        // base case
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        
        if(dp[ind1][ind2] == -1){
            // choice diagram code
            if(t1[ind1 - 1] == t2[ind2 - 1]){
                dp[ind1][ind2] = 1 + func(ind1 - 1, ind2 - 1, t1, t2, dp);
            }else{
                int f, s;
                f = func(ind1 - 1, ind2, t1, t2, dp);
                s = func(ind1, ind2 - 1, t1, t2, dp);
                dp[ind1][ind2] = max(f, s);
            }
        }
        return dp[ind1][ind2];
    }
};