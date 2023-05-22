//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string s){
        // code here 
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
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends