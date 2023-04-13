//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(sum + 1, vector<int>(n + 1, -1));
        return func(n, sum, arr, dp);
	}
	int func(int index, int lsum, int arr[], vector<vector<int>>&dp){
	    if(lsum == 0 && index == 0){
	        return 1;
	    }else if(index == 0){
	        return 0;
	    }
	    
	    if(dp[lsum][index] == -1){
    	    int p = 0, np = 0, mod = 1000000007;
    	    if(arr[index - 1] <= lsum){
    	        p = func(index - 1, lsum - arr[index - 1], arr, dp);
    	    }
    	    np = func(index - 1, lsum, arr, dp);
    	    
    	    dp[lsum][index] = (p + np)%mod;
	    }
    	return dp[lsum][index];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends