class Solution {
public:
    int func(vector<int>&n, vector<int>&dp, int ind, bool lastp){
        if(ind < 0) return 0;
        if(ind == 0){
            if(lastp) return 0;
            return n[0];
        }
        if(dp[ind] != -1) return dp[ind];
        int p, np;
        p = n[ind] + func(n, dp, ind-2, lastp);
        np = func(n, dp, ind-1, lastp);
        return dp[ind] = max(p, np);
    }
    int rob(vector<int>& n) {
        int size = n.size();
        if(size == 1) return n[0];
        vector<int>v1(size,-1), dp;
        dp = v1;
        int f = n[size-1]+func(n, dp, size-3, true);
        dp = v1;
        int s = func(n, dp, size-2, false);
        return max(f, s);
    }
};