class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int size = q.size();
        vector<long long>dp(size + 1, -1);
        return func(0, size, q, dp);
    }
    long long func(int ind, int &size, vector<vector<int>>&q, vector<long long>&dp){
        if(ind >= size){
            return 0;
        }
        if(dp[ind] == -1){
            long long p = 0, np = 0;
            p = q[ind][0] + func(ind + q[ind][1] + 1, size, q, dp);
            np = func(ind + 1, size, q, dp);
            dp[ind] = max(p, np);
        }
        return dp[ind];
    }
};