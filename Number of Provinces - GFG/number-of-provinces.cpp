//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&adj, vector<int>&rec, int n, int v){
        for(int i=0;i<v;i++){
            if(adj[n][i] && !rec[i]){
                rec[i] = 1;
                dfs(adj, rec, i, v);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>rec(V, 0);
        int count = 0;
        for(int i=0;i<V;i++){
            if(!rec[i]){
                count++;
                rec[i] = 1;
                dfs(adj, rec, i, V);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends