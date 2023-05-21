//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string s, int n) { 
    //complete the function here 
    string rev = s;
    reverse(rev.begin(), rev.end());
    int len = s.length();
    vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(s[i - 1] == rev[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return len - dp[len][len];
}