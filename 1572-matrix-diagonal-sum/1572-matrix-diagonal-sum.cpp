class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, size = mat.size();
        for(int i=0;i<size;i++){
            sum += mat[i][i];
            if(size - 1 - i != i){
                sum += mat[i][size - 1 - i];
            }
        }
        return sum;
    }
};