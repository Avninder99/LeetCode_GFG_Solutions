class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h_record=0, v_record=0, col_size = matrix.size(), row_size = matrix[0].size(), direction=0;
        vector<int>v1;
        
        int r_init=0, c_init=0;
        // c -> x, r -> y
        while(v1.size() < (col_size*row_size)){
            direction %= 4;
            if(direction == 0){
                int i2 = c_init;
                for(int i=0; i < (row_size - v_record) ; i++){
                    v1.push_back(matrix[r_init][i2]);
                    i2++;
                }
                h_record++;
                c_init = i2-1;
                
            }
            else if(direction == 1){
                int i2 = r_init+1;
                for(int i=0; i < (col_size - h_record);i++){
                    v1.push_back(matrix[i2][c_init]);
                    i2++;
                }
                v_record++;
                r_init = i2-1;
                
            }
            else if(direction == 2){
                int i2 = c_init-1;
                
                for(int i=0; i < (row_size - v_record) ; i++){
                    v1.push_back(matrix[r_init][i2]);
                    i2--;
                }
                h_record++;
                c_init = i2+1;
                
            }
            else{
                int i2 = r_init-1;
                for(int i=0; i < (col_size - h_record) ; i++){
                    v1.push_back(matrix[i2][c_init]);
                    i2--;
                }
                v_record++;
                r_init = i2+1;
                c_init++;
            }
            
            direction++;
        }
        return v1;
    }
};