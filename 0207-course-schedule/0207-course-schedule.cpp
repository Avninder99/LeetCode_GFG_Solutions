class Solution {
public:
    bool dfs(int curr, vector<int>&vis, vector<vector<int>>&adj, vector<int>&rec){
        vis[curr] = 1;
        for(auto itr: adj[curr]){
            if(vis[itr] == 0){
                if(rec[itr] == 1) continue;
                if(!dfs(itr, vis, adj, rec)){
                    return false;
                }
            }
            else return false;
        }
        rec[curr] = 1;
        vis[curr] = 0;
        return true;
    }
    bool canFinish(int nc, vector<vector<int>>& p) {
        vector<int>vis(nc, 0), rec(nc, 0);
        // rec -> 0 (not traversed), 1 (safe/ no need to traverse), 2 (loop)
        // vis stores visited record only during a single traversaL and gets reset every time
        // rec store if the node was traversed in previous iterations is does not contain a loop
        
        // rec is used to reduce time complexity from O(N^2) to O(N)
        // vis is used to find loop in a single traversal
        
        vector<vector<int>>adj(nc);
        for(auto itr: p){
            adj[itr[1]].push_back(itr[0]);
        }
        bool res = true;
        for(int i=0;i<nc;i++){
            if(vis[i] == 0 && rec[i] == 0){
                res = dfs(i, vis, adj, rec);
                if(!res) return false;
            }
        }
        return true;
    }
};