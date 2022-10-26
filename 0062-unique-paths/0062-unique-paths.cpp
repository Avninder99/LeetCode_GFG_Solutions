class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>m1(m, vector<int> (n, -1));
        m1[m-1][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 || j == n-1){
                    m1[i][j] = 1;
                }else{
                    m1[i][j] = m1[i+1][j] + m1[i][j+1];    
                }
                
            }
        }
        return m1[0][0];
    }
};