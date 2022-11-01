class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int rs = g[0].size(), cs = g.size();
        vector<int>v1;
        for(int i=0;i<rs;i++) v1.push_back(i);
        for(int i=0;i<cs;i++){
            for(int j=0;j<rs;j++){
                if(v1[j] == -1) continue;
                if( (g[i][v1[j]] == -1 && (v1[j]-1 < 0 || g[i][v1[j]-1] == 1)) ||
                    (g[i][v1[j]] == 1 && (v1[j]+1 > rs-1 || g[i][v1[j]+1] == -1)) )
                    v1[j] = -1;
                else v1[j] += g[i][v1[j]];
            }
        }
        return v1;
    }
};