//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int r, int c, int ncolor, int ocolor, vector<vector<int>>&im, int &rs, int &cs, vector<vector<int>>&dir){
        for(int i=0; i<4; i++){
            int tr = r + dir[i][0], tc = c + dir[i][1];
            if(tr >= 0 && tc >= 0 && tr < rs && tc < cs && im[tc][tr] == ocolor){
                im[tc][tr] = ncolor;
                dfs(tr, tc, ncolor, ocolor, im, rs, cs, dir);
                
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int nc) {
        // Code here 
        int rs = im[0].size(), cs = im.size(), oc = im[sr][sc];
        if(oc == nc){
            return im;
        }
        vector<vector<int>>dir;
        dir.push_back({0, -1});
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({-1, 0});
        im[sr][sc] = nc;
        dfs(sc, sr, nc, oc, im, rs, cs, dir);
        return im;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends