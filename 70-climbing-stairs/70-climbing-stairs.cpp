class Solution {
public:
    // Memorization
//     int func1(int num, int &n, vector<int>&dp){
//         if(num == n){
//             return 1;
//         }else if(num > n) return 0;
        
//         int one = 0, two = 0;
        
//         if(dp[num] != -1){
//             one = dp[num];
//         }else{
//             one = func1(num+1, n, dp);
//             dp[num] = one;
//         }
        
//         if(num+1 < n){
//             if(dp[num+1] != -1){
//                 two = dp[num+1];
//             }else{
//                 two = func1(num+2, n, dp);
//                 dp[num+1] = two;
//             }
//         }
        
//         return one + two;
//     }
    
    int climbStairs(int n) {
        vector<int>dp(n, 0);
        // int ans = func1(0, n, dp);
        // return ans;
        // Tabulation
        if(n==1) return 1;
        dp[n-1] = 1, dp[n-2] = 2;
        for(int i=n-3;i>=0;i--){
            dp[i] = dp[i+2] + dp[i+1]; 
        }
        return dp[0];
    }
};