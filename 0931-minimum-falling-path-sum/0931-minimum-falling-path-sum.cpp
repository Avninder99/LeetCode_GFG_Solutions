class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) 
    {
        int n = m.size();
        
        for(int row = 1; row < n; row++)
        {
            for(int col = 0; col < n; col++)
                
            {
                // int rowUp, leftUp, rightUp;
                
                int rowUp = m[row - 1][col];
                int leftUp = col > 0 ? m[row-1][col-1] : INT_MAX;
                int rightUp = col < n-1 ? m[row-1][col+1] : INT_MAX;
                
                // cout << rowUp << leftUp << rightUp << endl;
                
                m[row][col] += min(rowUp, min(leftUp, rightUp));
            }
        }
        int ans = INT_MAX;
        int end = n-1;
        
        for(int col = 0; col < n; col++)
        {
            ans = min(ans, m[end][col]);
        }
        
        return ans;
    }
    
    // int minFallingPathSum(vector<vector<int>>& m) {
    //     int s = m.size();
    //     for(int i=s-2; i>=0; i--){
    //         for(int j=0; j<s; j++){
    //             m[i][j] += min(m[i+1][j], min( (j < 1) ? 200 : m[i+1][j-1], (j+1 >= s) ? 200 : m[i+1][j+1] ));
    //         }
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0;i<s;i++){
    //         mini = min(mini, m[0][i]);
    //     }
    //     return mini;
    // }
};