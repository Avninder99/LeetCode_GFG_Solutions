class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int>vis(n, 0);
        vector<vector<int>>adj(n);
        
        for(auto itr: con){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
        int redundantE = 0, compCount = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                compCount++;
                vis[i] = 1;
                dfs(i, -1, adj, vis, redundantE);    
            }
        }
        redundantE /= 2;
        // cout << redundantE << " - " << compCount << endl;
        if(redundantE < compCount - 1){
            return -1;
        }
        return compCount - 1;
    }
    void dfs(int curr, int parent, vector<vector<int>>&adj, vector<int>&vis, int &redundantE){
        for(auto itr: adj[curr]){
            if(itr != parent){
                if(vis[itr] == 0){
                    vis[itr] = 1;
                    dfs(itr, curr, adj, vis, redundantE);
                }else{
                    redundantE++;
                }
            }
        }
        return;
    }
};