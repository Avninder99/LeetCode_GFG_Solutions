class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int maxi = 0, n = n1.size(), m = n2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        func(n, m, n1, n2, dp);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
    int func(int ind1, int ind2, vector<int>&n1, vector<int>&n2, vector<vector<int>>&dp){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        
        if(dp[ind1][ind2] == -1){
            if(n1[ind1 - 1] == n2[ind2 - 1]){
                dp[ind1][ind2] = 1 + func(ind1 - 1, ind2 - 1, n1, n2, dp);
            }
            else{
                dp[ind1][ind2] = 0;
            }
            func(ind1 - 1, ind2, n1, n2, dp); 
            func(ind1, ind2 - 1, n1, n2, dp);
        }
        return dp[ind1][ind2];
    }
};