//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(sum + 1, vector<long long int>(N + 1, -1));
        return func(coins, N - 1, sum, dp);
    }
    long long int func(int coins[], int index, int lsum, vector<vector<long long int>>&dp){
        if(lsum == 0){
            return 1;
        }
        
        if(index < 0){
            return 0;
        }
        
        if(dp[lsum][index] == -1){
            long long int p = 0, np = 0;
            
            if(coins[index] <= lsum){
                p = func(coins, index, lsum - coins[index], dp);
            }
            np = func(coins, index - 1, lsum, dp);
            
            dp[lsum][index] = p + np;
        }
        return dp[lsum][index];
    }
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