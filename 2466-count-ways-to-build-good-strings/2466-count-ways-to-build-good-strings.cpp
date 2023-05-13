class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high + 1, -1);
        return func(0, one, zero, low, high, dp);
    }
    int func(int cLen, int &one, int &zero, int &l, int &h, vector<int>&dp){
        if(cLen > h){   // just for safety (already handled by two below if conditions)
            return 0;
        }
        if(dp[cLen] == -1){
            long long res = 0;
            if(cLen >= l && cLen <= h){
                res += 1;
            }
            if(cLen + zero <= h){
                res += func(cLen + zero, one, zero, l, h, dp);
            }
            if(cLen + one <= h){
                res += func(cLen + one, one, zero, l, h, dp);
            }
            dp[cLen] = res%1000000007;
        }
        return dp[cLen];
    }
};