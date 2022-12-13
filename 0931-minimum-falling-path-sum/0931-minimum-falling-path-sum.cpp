class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int s = m.size();
        for(int i=s-2; i>=0; i--){
            for(int j=0; j<s; j++){
                m[i][j] += min(m[i+1][j], min( (j == 0) ? 10001 : m[i+1][j-1], (j == s-1) ? 10001 : m[i+1][j+1] ));
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<s;i++){
            mini = min(mini, m[0][i]);
        }
        return mini;
    }
};