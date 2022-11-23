class Solution {
public:
    set<char>s1;
    bool h_validator(vector<vector<char>>&b, int line){
        if(line==9) return true;
        
        s1.clear();
        
        for(int i=0;i<9;i++){
            if(b[line][i]!='.'){
                if(s1.count(b[line][i]) == 1) return false;
                s1.insert(b[line][i]);
            }
        }
        
        return h_validator(b, line+1);
    }
    
    bool v_validator(vector<vector<char>>&b, int line){
        if(line==9) return true;
        
        s1.clear();
        
        for(int i=0;i<9;i++){
            if(b[i][line]!='.'){
                if(s1.count(b[i][line]) == 1) return false;
                s1.insert(b[i][line]);
            }
        }
        
        return v_validator(b, line+1);
    }
    
    bool b_validator(vector<vector<char>>&b, int row, int col){
        
        s1.clear();
        
        for(int i=row;i<row+3;i++){
            
            for(int j=col;j<col+3;j++){
                
                if(b[i][j]!='.'){
                    if(s1.count(b[i][j]) == 1) return false;
                    s1.insert(b[i][j]);
                }
                
            }
            
        }
        
        if(row==6 && col==6){
            return true;
        }
        
        if(col<6){
            return b_validator(b, row, col+3);
        }else{
            return b_validator(b, row+3, 0);
        }
    }
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!h_validator(board, 0)){
            return false;
        }
        if(!v_validator(board, 0)){
            return false;
        }
        return b_validator(board, 0, 0);
    }
};