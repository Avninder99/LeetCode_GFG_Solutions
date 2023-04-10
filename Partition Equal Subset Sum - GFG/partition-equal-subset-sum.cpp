//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        if(sum%2 == 1){
            return false;
        }
        sum /= 2;
        
        // DP Memoization
        // vector<vector<int>>dp(sum + 1, vector<int>(N + 1, -1));
        // return func(N, sum, arr, dp);
        
        
        // DP Tabulation
        vector<vector<int>>t(sum + 1, vector<int>(N + 1, -1));
        
        for(int i=0;i<=sum;i++){
            t[i][0] = 0;
        }
        for(int i=0;i<=N;i++){
            t[0][i] = 1;
        }
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=N;j++){
                bool p = false, np = false;
                if(arr[j - 1] <= i){
                    p = t[i - arr[j - 1]][j - 1];
                }
                if(!p){
                    np = t[i][j - 1];
                }
                t[i][j] = (p || np) ? 1 : 0;
            }
        }
        
        return t[sum][N];
    }
    
    // bool func(int index, int lsum, int arr[], vector<vector<int>>&dp){
    //     if(lsum == 0){
    //         return true;
    //     }else if(index == 0){
    //         return false;
    //     }
        
    //     if(dp[lsum][index] == -1){
    //         bool p = false, np = false;
    //         if(arr[index - 1] <= lsum){
    //             p = func(index - 1, lsum - arr[index - 1], arr, dp);
    //         }
    //         if(!p){
    //             np = func(index - 1, lsum, arr, dp);
    //         }
    //         dp[lsum][index] = (p || np) ? 1 : 0;
    //     }
        
    //     return dp[lsum][index];
    // }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends