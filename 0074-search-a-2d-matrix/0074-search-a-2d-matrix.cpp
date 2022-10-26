class Solution {
public:
    int interpolation_search_h(vector<vector<int>>m, int n, int size, int h){
        if(m[h][size-1]<n) return false;
        int low = 0, high = size-1, pos, prev=-1;
        while(high >= low){
            if(low==high){
                if (m[h][low] == n) return low;
                return -1;
            }
            pos = low + ( ( (n-m[h][low]) / (m[h][high] - m[h][low]) ) * (high - low) );
            if(m[h][pos] == n){
                return pos;
            }else if(m[h][pos] > n){
                high = pos-1;
            }else{
                low = pos+1;
            }
        }
        return -1;
    }
    
    int bs(vector<vector<int>>m, int t, int size, int h){
        int low = 0, high = size-1, mid;
        while(low<=high){
            mid = (high+low)/2;
            if(m[h][mid] == t){
                return mid;
            }else if(m[h][mid]>t){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // interpolation search approach
        
        if(target < matrix[0][0]) return false;
        
        int size1 = matrix.size(),row,prev;
        
        for(int i = size1-1;i>=0;i--){
            cout << matrix[i][0] << endl;
            if(matrix[i][0]==target){
                return true;
            }else if(matrix[i][0]<target){
                row = i;
                break;
            }
        }
        
        int size2 = matrix[row].size();
        // int col = interpolation_search_h(matrix,target,size2,row);
        
        int col = bs(matrix,target,size2,row);
        
        if(col == -1) return false;
        // if(matrix[row][col]==target){
        //     return true;
        // }
        return true;
        
    }
};