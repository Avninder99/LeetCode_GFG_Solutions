class Solution {
public:
    int minDistance(string w1, string w2) {
        int len1 = w1.length(), len2 = w2.length();
        vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(w1[i - 1] == w2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int lcs = dp[len1][len2], res = (len1 - lcs) + (len2 - lcs);
        return res;
    }
};