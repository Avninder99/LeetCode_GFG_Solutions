//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int p[], int n) {
        //code here
        int ind = n;
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return func(ind, n, p, dp);
    }
    int func(int ind, int rLen, int p[], vector<vector<int>>&dp){
        if(ind == 0 || rLen == 0){
            return 0;
        }
        
        if(dp[ind][rLen] == -1){
            int pi = 0, np = 0;
            if(ind <= rLen){
                pi = p[ind - 1] + func(ind, rLen - ind, p, dp);
            }
            np = func(ind - 1, rLen, p, dp);
            dp[ind][rLen] = max(pi, np);
        }
        return dp[ind][rLen];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends