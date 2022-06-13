class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int lvl = triangle.size(), lvl_size;
        
        for(int i=lvl-2;i>=0;i--){
            lvl_size = triangle[i].size();
            for(int j=0;j<lvl_size;j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};