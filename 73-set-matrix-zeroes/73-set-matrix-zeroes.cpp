class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int rsize = m[0].size(), csize = m.size();
        vector<int>rv(rsize, 0);
        vector<int>cv(csize, 0);
        
        for(int i=0;i<csize;i++){
            for(int j=0;j<rsize;j++){
                if(m[i][j] == 0){
                    cv[i] = 1;
                    rv[j] = 1;
                }
            }
        }
        
        for(int i=0;i<csize;i++){
            if(cv[i] == 1){
                for(int j=0;j<rsize;j++){
                    m[i][j] = 0;   
                }    
            }
        }
        
        for(int i=0;i<rsize;i++){
            if(rv[i] == 1){
                for(int j=0;j<csize;j++){
                    m[j][i] = 0;   
                }    
            }
        }
    }
};