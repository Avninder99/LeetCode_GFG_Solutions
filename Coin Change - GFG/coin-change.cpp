//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        // DP Memoization
        // vector<vector<long long int>>dp(sum + 1, vector<long long int>(N + 1, -1));
        // return func(coins, N, sum, dp);
        
        // DP Tabulation
        vector<vector<long long int>>t(sum + 1, vector<long long int>(N + 1, -1));
        
        for(int i=0;i<sum+1;i++){
            t[i][0] = 0;
        }
        for(int i=0;i<N+1;i++){
            t[0][i] = 1;
        }
        
        long long int p, np;
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=N;j++){
                p = 0, np = 0;
                if(coins[j - 1] <= i){
                    p = t[i - coins[j - 1]][j];
                }
                np = t[i][j - 1];
                
                t[i][j] = p + np;
            }
        }
        
        return t[sum][N];
    }
    
    // DP Memoization function
    
    // long long int func(int coins[], int index, int lsum, vector<vector<long long int>>&dp){
    //     if(lsum == 0){
    //         return 1;
    //     }
        
    //     if(index == 0){
    //         return 0;
    //     }
        
    //     if(dp[lsum][index] == -1){
    //         long long int p = 0, np = 0;
            
    //         if(coins[index - 1] <= lsum){
    //             p = func(coins, index, lsum - coins[index - 1], dp);
    //         }
    //         np = func(coins, index - 1, lsum, dp);
            
    //         dp[lsum][index] = p + np;
    //     }
    //     return dp[lsum][index];
    // }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends