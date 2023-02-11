class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        queue<vector<int>>q1;
        // [currInd, dist to reach this, prevCol]
        // prevCol -> 0 = red, 1 = blue
        vector<vector<int>>adjR(n), adjB(n), rec(n, vector<int>(2, INT_MAX));
        // rec -> 0 - red, 1 - blue
        vector<int>res(n);
        for(auto itr: r){
            adjR[itr[0]].push_back(itr[1]);
        }
        for(auto itr: b){
            adjB[itr[0]].push_back(itr[1]);
        }
        
        q1.push({0, 0, 0});
        q1.push({0, 0, 1});
        
        while(!q1.empty()){
            vector<int>h = q1.front();
            q1.pop();
            rec[h[0]][h[2]] = min(rec[h[0]][h[2]], h[1]);
                
            if(h[2] == 0){
                for(auto itr: adjB[h[0]]){
                    if(rec[itr][1] > h[1] + 1){
                        q1.push({itr, h[1] + 1, 1});
                    }
                }
            }else{
                for(auto itr: adjR[h[0]]){
                    if(rec[itr][0] > h[1] + 1){
                        q1.push({itr, h[1] + 1, 0});
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            res[i] = min(rec[i][0], rec[i][1]);
            if(res[i] == INT_MAX){
                res[i] = -1;
            }
        }
        
        return res;
    }
};