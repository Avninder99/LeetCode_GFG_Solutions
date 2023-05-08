class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        vector<vector<int>>dp(nums.size() + 1, vector<int>(5000, -1)); // 4003 actually needed
        return func(nums.size(), t, nums, dp);
    }
    int func(int ind, int t, vector<int>&nums, vector<vector<int>>&dp){
        if(ind == 0){
            if(t == 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][t + 2001] == -1){
            int p = 0, n = 0;
            p = func(ind - 1, t - nums[ind - 1], nums, dp);
            n = func(ind - 1, t + nums[ind - 1], nums, dp);
            dp[ind][t + 2001] = p + n;    
        }
        return dp[ind][t + 2001];
    }
};