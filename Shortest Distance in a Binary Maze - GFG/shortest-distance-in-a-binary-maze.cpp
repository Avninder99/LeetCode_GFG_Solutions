//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &g, pair<int, int> s, pair<int, int> d) {
        // code here
        vector<vector<int>>dirc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>>q1;
        int cs = g.size(), rs = g[0].size(), distance = 0;
        q1.push(s);
        q1.push({-1, -1});
        
        while(q1.size() > 1){
            
            pair<int, int>holder = q1.front();
            q1.pop();
            
            if(holder.first == -1){
                distance++;
                q1.push({-1, -1});
                continue;
            }
            
            if(holder.first == d.first && holder.second == d.second) return distance;
            
            for(auto itr: dirc){
                int rt = holder.second + itr[1], ct = holder.first + itr[0];
                
                if(rt < 0 || ct < 0 || rt >= rs || ct >= cs || g[ct][rt] == 0){
                    continue;
                }
                
                g[ct][rt] = 0;
                q1.push({ct, rt});
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends