//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        else if(a[0]==b[0]&& a[1]==b[1]){
            return a[2]>b[2];
        }
        else{
            return a[0]<=b[0];
        }
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(),intervals.end());
        vector<int> dp(n,0);
       
        for(int i=0;i<n;i++)
        {
            dp[i]=intervals[i][2];
        }
        for(int i=0;i<n;i++)
        {
            dp[i]=intervals[i][2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(intervals[j][1]<=intervals[i][0]&& intervals[j][0]<intervals[i][0])
                {
                    dp[i]=max(dp[i],intervals[i][2]+dp[j]);
                }
            }
        }
        int ans =0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends