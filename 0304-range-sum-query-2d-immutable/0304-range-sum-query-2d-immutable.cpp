class NumMatrix {
public:
    vector<vector<int>>dp;
    int rs, cs;
    
    NumMatrix(vector<vector<int>>& m) {
        dp = m;
        rs = m[0].size();
        cs = m.size();
        
        // set last column (|)
        for(int i=cs-2;i>=0;i--) dp[i][rs-1] += dp[i+1][rs-1];
        // set last row (-)
        for(int j=rs-2;j>=0;j--) dp[cs-1][j] += dp[cs-1][j+1];
        
        // set the remaining dp matrix
        for(int i=cs-2;i>=0;i--){
            for(int j=rs-2;j>=0;j--){
                dp[i][j] += (dp[i][j+1] + dp[i+1][j] - dp[i+1][j+1]);
            }
        }
    }
    
    int sumRegion(int c1, int r1, int c2, int r2) {
        // i have swapped the names of r1 <-> c1 and r2 <-> c2 to match my coordinate assignment
        int A = dp[c1][r1], B = 0, C = 0, D = 0;
        if(r2+1 < rs) B = dp[c1][r2+1];
        if(c2+1 < cs) C = dp[c2+1][r1];
        if(r2+1 < rs && c2+1 < cs) D = dp[c2+1][r2+1];
        return (A - B - C + D);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */