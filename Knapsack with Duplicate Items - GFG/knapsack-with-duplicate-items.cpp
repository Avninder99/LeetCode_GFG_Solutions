//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int>dp(W + 1, -1);
        return func(W, val, wt, N, dp);
    }
    int func(int wLeft, int val[], int wt[], int &n, vector<int>&dp){
        if(wLeft <= 0){
            return 0;
        }
        if(dp[wLeft] == -1){
            int maxi = 0;
            for(int i=0;i<n;i++){
                if(wLeft >= wt[i]){
                    maxi = max(maxi, func(wLeft - wt[i], val, wt, n, dp) + val[i]);
                }
            }
            dp[wLeft] = maxi;
        }
        return dp[wLeft];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends