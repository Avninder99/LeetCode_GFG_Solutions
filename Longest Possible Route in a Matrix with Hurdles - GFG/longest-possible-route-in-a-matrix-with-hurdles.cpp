// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int xd, yd, max_count=0, xm, ym;
    
    void func1(int x, int y, int counter, int dx[], int dy[], vector<vector<int>>&m){
        if(x == xd && y == yd){
            if(counter > max_count) max_count = counter;
            return;
        }
        m[x][y] = 0;
        counter++;
        for(int i=0;i<4;i++){
            x += dx[i];
            y += dy[i];
            
            if( x >= 0 && x < xm && y >= 0 && y < ym && m[x][y] == 1){
                func1(x, y, counter, dx, dy, m);
            }
            
            x -= dx[i];
            y -= dy[i];
        }
        m[x][y] = 1;
        return;
    }
    
    int longestPath(vector<vector<int>> m, int xs, int ys, int Xd, int Yd)
    {
        // code here
        if(m[xs][ys] == 0 || m[Xd][Yd] == 0) return -1;
        xd = Xd;
        yd = Yd;
        ym = m[0].size(), xm = m.size();
        int direcX[4] = {-1, 0, 1, 0};
        int direcY[4] = {0, 1, 0, -1};
        func1(xs, ys, 0, direcX, direcY, m);
        return max_count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends