class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size(), marker;
        vector<int>vis(n, 0);
        
        queue<pair<int, int>>q1;
        // curr node, color
        
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                
                // perform m-coloring with 2 colors => (11, 12)
                
                vis[i] == 11;
                q1.push({i, 11});
                
                while(!q1.empty()){
                    pair<int, int>holder = q1.front();
                    q1.pop();
                    
                    for(auto itr: g[holder.first]){
                        if(vis[itr] == 0){
                            marker = (holder.second == 11) ? 12 : 11;
                            vis[itr] = marker;
                            q1.push({itr, marker});
                        }else if(vis[itr] == holder.second){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};