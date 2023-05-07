//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        long long int sum = 0, lsum = 0;
        for(auto itr: arr){
            sum += itr;
        }
        lsum = (sum - d)/2;
        if((sum - d)%2 == 1 || d > sum){
            return 0;
        }
        vector<vector<long long int>>dp(lsum + 1, vector<long long int>(n + 1, -1));
        return (func(n, lsum, arr, dp)%1000000007);
    }
    long long int func(int ind, int lsum, vector<int>&arr, vector<vector<long long int>>&dp){
        if(ind == 0){
            if(lsum == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[lsum][ind] == -1){
            long long int p = 0, np = 0;
            
            if(arr[ind - 1] <= lsum){
                p = func(ind - 1, lsum - arr[ind - 1], arr, dp);
            }
            np = func(ind - 1, lsum, arr, dp);
            dp[lsum][ind] = (p + np)%1000000007;
        }
        return dp[lsum][ind];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends