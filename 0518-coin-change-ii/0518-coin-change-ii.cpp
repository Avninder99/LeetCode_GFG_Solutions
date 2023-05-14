class Solution {
public:
    int change(int amt, vector<int>& c) {
        int size = c.size();
        vector<vector<int>>dp(size + 1, vector<int>(amt + 1, -1));
        for(int i=0;i<=amt;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=size;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=size;i++){
            for(int j=1;j<=amt;j++){
                int pickCoin = 0, notPickCoin = 0;
                if(c[i - 1] <= j){
                    pickCoin = dp[i][j - c[i - 1]];
                }
                notPickCoin = dp[i - 1][j];
                dp[i][j] = pickCoin + notPickCoin;
            }
        }
        return dp[size][amt];
    }
};