//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool dp[n][n][n + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][0] = true;
                }
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    for (int len1 = 1; len1 <= len - 1; len1++) {
                        int len2 = len - len1;
                        dp[i][j][len - 1] |= dp[i][j][len1 - 1] && dp[i + len1][j + len1][len2 - 1];
                        dp[i][j][len - 1] |= dp[i][j + len2][len1 - 1] && dp[i + len1][j][len2 - 1];
                    }
                }
            }
        }
        return dp[0][0][n - 1];
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends