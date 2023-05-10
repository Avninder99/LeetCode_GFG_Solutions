class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int h_record=0, v_record=0, col_size = n, row_size = n, direction=0, tsize=n*n;
        vector<int>v1;
        vector<vector<int>>matrix(n,v1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i].push_back(0);
            }
        }
        
        int r_init=0, c_init=0,counter=1;
        // c -> x, r -> y
        while(counter <= tsize){
            direction %= 4;
            if(direction == 0){
                int i2 = c_init;
                for(int i=0; i < (row_size - v_record) ; i++){
                    matrix[r_init][i2] = counter;
                    counter++;
                    i2++;
                }
                h_record++;
                c_init = i2-1;
                
            }
            else if(direction == 1){
                int i2 = r_init+1;
                for(int i=0; i < (col_size - h_record);i++){
                    matrix[i2][c_init] = counter;
                    counter++;
                    i2++;
                }
                v_record++;
                r_init = i2-1;
                
            }
            else if(direction == 2){
                int i2 = c_init-1;
                
                for(int i=0; i < (row_size - v_record) ; i++){
                    matrix[r_init][i2] = counter;
                    counter++;
                    i2--;
                }
                h_record++;
                c_init = i2+1;
                
            }
            else{
                int i2 = r_init-1;
                for(int i=0; i < (col_size - h_record) ; i++){
                    matrix[i2][c_init] = counter;
                    counter++;
                    i2--;
                }
                v_record++;
                r_init = i2+1;
                c_init++;
            }
            direction++;
        }
        return matrix;
    }
};