class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int pVal = 0, csize=g.size(), rsize=g[0].size(),temp;
        for(int i=0;i<csize;i++){
            for(int j=0;j<rsize;j++){
                if(g[i][j]==1){
                    // temp=0;
                    if(i==0 || !g[i-1][j]){
                        pVal++;
                    }
                    if(j==rsize-1 || !g[i][j+1]){
                        pVal++;
                    }
                    if(i==csize-1 || !g[i+1][j]){
                        pVal++;
                    }
                    if(j==0 || !g[i][j-1]){
                        pVal++;
                    }    
                }
            }
        }
        return pVal;
    }
};