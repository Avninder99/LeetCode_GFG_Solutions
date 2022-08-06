class Solution {
public:
    
    
    void rotater(vector<vector<int>>&m, int lL, int rL, int uL, int dL, int rF=0){
        
        if(rF <= 0) return;
        queue<int>q1;
        
        for(int j=0;j<4;j++){

            if(j==0){
                for(int i=dL;i>uL;i--){
                    q1.push(m[i][lL]);
                }
                for(int i=lL;i<rL;i++){
                    q1.push(m[uL][i]);
                    m[uL][i] = q1.front();
                    q1.pop();
                }

            }else if(j==1){

                for(int i=uL;i<dL;i++){
                    q1.push(m[i][rL]);
                    m[i][rL] = q1.front();
                    q1.pop();
                }

            }else if(j==2){

                for(int i=rL;i>lL;i--){
                    q1.push(m[dL][i]);
                    m[dL][i] = q1.front();
                    q1.pop();
                }

            }else{

                for(int i=dL;i>uL;i--){
                    q1.push(m[i][lL]);
                    m[i][lL] = q1.front();
                    q1.pop();
                }

            }

        }
        rotater(m, ++lL, --rL, ++uL, --dL, --rF);
    }
    
    
    void rotate(vector<vector<int>>& m) {
        int observed, n = m[0].size();
        int runFreq = (int)n/2;
        // int lLimit=0, rLimit=n-1, uLimit=0, dLimit=n-1;
        
        rotater(m, 0, n-1, 0, n-1, runFreq);
        
    }
};