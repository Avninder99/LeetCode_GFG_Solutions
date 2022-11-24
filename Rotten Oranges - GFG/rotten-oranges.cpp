//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& g) {
        // Code here
        int rs = g[0].size(), cs = g.size(), count = 0;
        queue<vector<int>>q1;
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g[i][j] == 2){
                    q1.push({i, j});  
                }
            }
        }
        q1.push({-1,-1});
        
        vector<vector<int>>dir;
        dir.push_back({0, -1});
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({-1, 0});
        
        while(q1.size() > 1){
            if(q1.front()[0] == -1){
                q1.push({-1, -1});
                q1.pop();
                count++;
            }else{
                int r = q1.front()[1], c = q1.front()[0];
                q1.pop();
                for(int i=0;i<4;i++){
                    int tr = r + dir[i][0], tc = c + dir[i][1];
                    if(tr >= 0 && tc >= 0 && tr < rs && tc < cs && g[tc][tr] == 1){
                        g[tc][tr] = 2;
                        q1.push({tc, tr});
                    }
                }
            }
        }
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(g[i][j] == 1){
                    return -1;  
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends