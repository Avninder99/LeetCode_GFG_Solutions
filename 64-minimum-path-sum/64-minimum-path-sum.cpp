class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int sum=0, rsize = g[0].size(), csize = g.size(), dSum, rSum, min1;
        vector<vector<int>>v1(csize, vector<int>(rsize, 0));
        
        for(int i=csize-1;i>=0;i--){
            for(int j=rsize-1;j>=0;j--){
                
                if(i==csize-1){
                    dSum = INT_MAX;
                }else{
                    dSum = g[i+1][j];
                }
                
                if(j==rsize-1){
                    rSum = INT_MAX;
                }else{
                    rSum = g[i][j+1];
                }
                min1 = min(dSum, rSum);
                if(min1 < INT_MAX) g[i][j] += min(dSum, rSum);
            }
        }
        return g[0][0];
    }
};