class Solution {
public:
    bool dfs(int curr, vector<int>&vis, vector<vector<int>>&adj){
        vis[curr] = 1;
        for(auto itr: adj[curr]){
            if(vis[itr] == 2) continue;
            if(vis[itr] == 0){
                if(!dfs(itr, vis, adj)){
                    return false;
                }
            }
            else return false;
        }
        vis[curr] = 2;
        return true;
    }
    bool canFinish(int nc, vector<vector<int>>& p) {
        vector<int>vis(nc, 0);
        // 0 -> not visited
        // 1 -> visited in this iteration (all children nodes haven't been traversed yet)
        // 2 -> safe node (visited in previous iteration, No child contains self loop)
        vector<vector<int>>adj(nc);
        for(auto itr: p){
            adj[itr[1]].push_back(itr[0]);
        }
        bool res = true;
        for(int i=0;i<nc;i++){
            if(vis[i] == 0){
                if(!dfs(i, vis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};