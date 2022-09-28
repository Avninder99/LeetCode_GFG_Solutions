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
        if(size == 2) return max(n[0], n[1]);
        vector<int>v1(size,-1), dp;
        dp = v1;
        dp[0] = n[0], dp[1] = n[1];
        for(int i=2;i<size;i++){
            int t,nt;
            t = n[i];
            if(i>2) t += dp[i-2];
            nt = dp[i-1];
            dp[i] = max(t,nt);
        }
        int f = max(dp[size-1], dp[size-2]);
        
        dp = v1;
        dp[0] = n[0], dp[1] = n[1];
        for(int i=1;i<size-1;i++){
            int t,nt;
            t = n[i];
            if(i>1) t += dp[i-2];
            nt = dp[i-1];
            dp[i] = max(t,nt);
        }
        int s = max(dp[size-2], dp[size-3]);
        return max(f, s);
    }
};