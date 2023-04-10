//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // vector<vector<int>>dp(sum + 1, vector<int>(n + 1, -1));
        // return func(n, sum, arr, dp);
        
        vector<vector<bool>>t(sum + 1, vector<bool>(n + 1, -1));
        for(int i=0;i<=sum;i++){
            t[i][0] = false;
        }
        for(int i=0;i<=n;i++){
            t[0][i] = true;
        }
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=n;j++){
                bool p = false, np = false;
                if(i >= arr[j - 1]){
                    p = t[i - arr[j - 1]][j - 1];
                }
                if(!p){
                    np = t[i][j - 1];
                }
                t[i][j] = p || np;
            }
        }
        return t[sum][n];
    }
    
    // bool func(int index, int lsum, vector<int>&arr, vector<vector<int>>&dp){
    //     if(lsum == 0){
    //         return true;
    //     }else if(index == 0){
    //         return false;
    //     }
        
    //     if(dp[lsum][index] == -1){
    //         bool p = false, np = false;
    //         if(lsum >= arr[index - 1]){
    //             p = func(index - 1, lsum - arr[index - 1], arr, dp);
    //         }
    //         if(!p){
    //             np = func(index - 1, lsum, arr, dp);
    //         }
    //         dp[lsum][index] = p || np;
    //     }
    //     return dp[lsum][index];
    // }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends