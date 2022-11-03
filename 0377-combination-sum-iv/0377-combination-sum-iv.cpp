class Solution {
public:
    int func(int ind, int sum, vector<vector<int>>&dp, vector<int>&n, int &s){
        // cout << sum << endl;
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int c=0;
        for(int i=0;i<s;i++) c += func(i, sum-n[i], dp, n, s);
        dp[ind][sum] = c;
        return dp[ind][sum];
    }
    int combinationSum4(vector<int>& n, int t) {
        int sum = 0, size=n.size();
        for(auto itr: n) sum += itr;
        vector<vector<int>>dp(size+1, vector<int>(t+1, -1));
        return func(size-1, t, dp, n, size);
    }
};