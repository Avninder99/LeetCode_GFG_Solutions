//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int rs = heights[0].size(), cs = heights.size();
        
        vector<vector<int>>directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // to move in up, right, down, left directions respectively
        
        vector<vector<int>>records(cs, vector<int>(rs, 1e7));
        // will store maxi edge in path till now
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        // maxi edge along the path, col, row
        
        records[0][0] = 0;
        pq.push({0, 0, 0});
        
        while(!pq.empty()){
            vector<int>holder = pq.top();
            pq.pop();
            
            for(vector<int> itr: directions){
                int originalR = holder[2], originalC = holder[1];
                int newRow = holder[2] + itr[1], newCol = holder[1] + itr[0];
                if(newRow < 0 || newCol < 0 || newRow >= rs || newCol >= cs) continue;
                
                int maxi = max(
                    records[originalC][originalR], 
                    abs( heights[newCol][newRow] - heights[originalC][originalR] ) 
                );
                
                if(records[newCol][newRow] > maxi){
                    records[newCol][newRow] = maxi;
                    pq.push({maxi, newCol, newRow});
                }
            }
        }
        
        return records[cs - 1][rs - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends