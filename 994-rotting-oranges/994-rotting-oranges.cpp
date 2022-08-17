class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int, int>>q1;
        int csize = g.size(), rsize = g[0].size(), counter=0;
        
        for(int i=0;i<csize;i++){
            for(int j=0;j<rsize;j++){
                if(g[i][j] == 2){
                    q1.push({i,j});
                }
            }
        }
        q1.push({50, 50});
        
        while(q1.size() > 1){
            if(q1.front().first == 50){
                q1.push({50, 50});
                counter++;
            }else{
                int i = q1.front().first, j = q1.front().second;
                if(i-1 >= 0 && g[i-1][j] == 1){
                    g[i-1][j] = 2;
                    q1.push({i-1, j});
                }
                if(j+1 < rsize && g[i][j+1] == 1){
                    g[i][j+1] = 2;
                    q1.push({i, j+1});
                }
                if(i+1 < csize && g[i+1][j] == 1){
                    g[i+1][j] = 2;
                    q1.push({i+1, j});
                }
                if(j-1 >= 0 && g[i][j-1] == 1){
                    g[i][j-1] = 2;
                    q1.push({i, j-1});
                }
            }
            q1.pop();
        }
        
        for(int i=0;i<csize;i++){
            for(int j=0;j<rsize;j++){
                if(g[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return counter;
    }
};