//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &c) {
        // write your code here
        int n = c.size();
        if(n == 0) return 0;
        
        int k = c[0].size();
        if(n == 1 && k > 0) return *min_element(c[0].begin(), c[0].end());
        if(k < 2) return -1;
        
        for(int i=n-2;i>=0;i--){
            int min1 = 1e7, col1, min2 = 1e7, col2;
            for(int j=0;j<k;j++){
                if(c[i+1][j] < min1){
                    min2 = min1;
                    col2 = col1;
                    min1 = c[i+1][j];
                    col1 = j;
                }else if(c[i+1][j] < min2){
                    min2 = c[i+1][j];
                    col2 = j;
                }
            }
            
            for(int j=0;j<k;j++){
                if(j != col1){
                    c[i][j] += min1;
                }else{
                    c[i][j] += min2;
                }
            }
        }
        int res = 1e9;
        for(int i=0;i<k;i++){
            res = min(res, c[0][i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends