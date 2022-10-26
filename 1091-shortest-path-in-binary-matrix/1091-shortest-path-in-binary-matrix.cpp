class Solution {
public:
    // int size;
    // vector<vector<int>>v1;
    // queue<pair<int,int>>q1;
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& v1) {
        int size = v1.size();
        
        if(v1[0][0] == 1 || v1[size-1][size-1] == 1){
            return -1;
        }else if(size == 1) return 1;
        
        int dicr[] = {-1,-1,0,1,1,1,0,-1};
        int dicc[] = {0,1,1,1,0,-1,-1,-1};
        
        queue<pair<int,int>>q1;
        q1.push({-5,-5});
        q1.push({0,0});
        int count = 0, row, col;
        
        
        
        
        
        
        while(q1.size() > 1){
            if(q1.front().first == -5){
                q1.push({-5,-5});
                q1.pop();
                count++;
                continue;
            }
            row = q1.front().first;
            col = q1.front().second;
            q1.pop();
            // v1[row][col] = 1;
            if(row == size-1 && col == size-1){
                return count;
            }
            for(int i=1;i<9;i++){
                int nx = row + dicr[i-1], ny = col + dicc[i-1];
                
                if( nx >= 0 && ny >= 0 && nx < size && ny < size && v1[nx][ny] == 0){
                    q1.push({nx, ny});
                    v1[nx][ny] = 1;
                }
                
            }
            
            
        }
        return -1;
    }
};