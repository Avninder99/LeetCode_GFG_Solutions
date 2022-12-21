class Solution {
public:
    void dfs(int node, vector<vector<int>>&drec, bool &res, int alt, vector<int>&rec){
        alt *= -1;
        for(auto itr: drec[node]){
            if(rec[itr] == 0){
                rec[itr] = alt;
                dfs(itr, drec, res, alt, rec);
            }else if(rec[itr] == rec[node]){
                res = false;
                return;
            }
            if(!res){
                return;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        if(n < 3) return true;
        vector<vector<int>>drec(n+1);
        
        for(auto itr: d){
            drec[itr[0]].push_back(itr[1]);
            drec[itr[1]].push_back(itr[0]);
        }
        
        vector<int>rec(n+1, 0);   // 0 - unvisited, 1 - group 1, -1 - group 2
        // if we encounter any odd length loop we return false;
        // for this i am using an alternating visit record approach
        // as long as neighbours have different group/tag res stays true
        
        // 1 - 2 - 3 - 4
        // 1  -1   1  -1
        bool res = true;
        
        for(int i=1;i<n+1;i++){
            if(rec[i] == 0){
                rec[i] = 1;
                dfs(i, drec, res, 1, rec);
            }
            if(!res) return false;
        }
        
        return res;
        
    }
};