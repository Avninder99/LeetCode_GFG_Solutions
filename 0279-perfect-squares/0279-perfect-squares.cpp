class Solution {
public:
    int solve(int n, vector<int>&sq, vector<int> &dp) {
        if(n == 0){
            return 0;
        }
        
        if (dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX; 
        
        for(int i = 0; i < sq.size(); i++) {
            if (sq[i] > n)
                break;
            
            ans = min(ans, 1 + solve(n - sq[i], sq, dp));
        }
        
        return dp[n] = ans;
        
    }
    int numSquares(int n) {
        vector<int>sq;
        vector<int> dp(n + 1, 0);
        // dp[0] = 0;
        int i = 1;
        while(i*i <= n){
            sq.push_back(i*i);
            i++;
        }
        
        for (int t = 1; t<=n; t++) {
            int ans = INT_MAX;
            for (int s : sq) {
                if (s > t)
                    break;
                
                ans = min(ans, 1 + dp[t - s]);
            }
            
            dp[t] = ans;
        }
        
        
        return dp[n];
        
    }
};