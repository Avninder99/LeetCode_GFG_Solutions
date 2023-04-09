//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Your code here
        
        // DP Memoization
        // vector<vector<int>>dp(W + 1, vector<int>(n, -1));
        // return func(W, 0, wt, val, n, dp);
        
        
        // DP Tabulation
        vector<vector<int>>t(W + 1, vector<int>(n + 1, -1));
        
        for(int i=0;i<=W;i++){
            t[i][n] = 0;
        }
        for(int i=0;i<=n;i++){
            t[0][i] = 0;
        }
        
        int p, np;
        for(int i=1;i<=W;i++){
            p = 0, np = 0;
            for(int j=n-1;j>=0;j--){
                if(i >= wt[j]){
                    p = val[j] + t[i - wt[j]][j + 1];
                }
                np = t[i][j + 1];
                t[i][j] = max(p, np);
            }
        }
        
        return t[W][0];
    }
    
    // DP Memoization function
    // int func(int wLeft, int index, int wt[], int val[], int &n, vector<vector<int>>&dp){
    //     if(index >= n || wLeft <= 0){
    //         return 0;
    //     }
    //     if(dp[wLeft][index] == -1){
    //         int p = 0, np = 0;
    //         if(wLeft >= wt[index]){
    //             p = val[index] + func(wLeft - wt[index], index + 1, wt, val, n, dp);
    //         }
    //         np = func(wLeft, index + 1, wt, val, n, dp);
    //         dp[wLeft][index] = max(p, np);
    //     }
    //     return dp[wLeft][index];
    // }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends