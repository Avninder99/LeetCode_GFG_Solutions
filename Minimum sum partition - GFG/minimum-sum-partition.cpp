//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long int sum = 0, holder;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    vector<vector<long long int>>dp(sum + 1, vector<long long int>(n + 1, -1));
	    holder = func(n, sum/2, arr, dp);
	    return abs(sum - holder - holder);
	}
	long long int func(int ind, long long int ls, int arr[], vector<vector<long long int>>&dp){
	    if(ind == 0 || ls == 0){
	        return 0;
	    }
	    
	    if(dp[ls][ind] == -1){
    	    long long int p = 0, np = 0;
    	    if(arr[ind - 1] <= ls){
    	        p = arr[ind - 1] + func(ind - 1, ls - arr[ind - 1], arr, dp);
    	    }
    	    np = func(ind - 1, ls, arr, dp);
    	    
    	    if(ls - p < ls - np){
    	        dp[ls][ind] = p;
    	    }else{
    	        dp[ls][ind] = np;
    	    }
	    }
	    return dp[ls][ind];
	}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends