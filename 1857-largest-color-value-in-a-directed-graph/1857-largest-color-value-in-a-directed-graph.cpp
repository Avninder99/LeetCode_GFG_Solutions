class Solution {
public:
    int largestPathValue(string c, vector<vector<int>>& e) {
        int n = c.length(), m = e.size();
        vector<int>ind(n, 0);
        vector<vector<int>>adj(n);
        vector<vector<int>>rec(n, vector<int>(0));
        // size => 0 -> unvisited, 1 -> visited but in process (for loop detection), 26 -> visited and processed
        
        for(auto itr: e){
            adj[itr[0]].push_back(itr[1]);
            ind[itr[1]]++;
        }
        
        int maxi = -1;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(ind[i] == 0){
                res = dfs(i, c, adj, rec);
                if(res.size() == 1){
                    return -1;
                }else{
                    for(auto itr: res){
                        if(itr > maxi){
                            maxi = itr;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(rec[i].empty()){
                return -1;
            }
        }
        return maxi;
    }
    vector<int> dfs(int curr, string &c, vector<vector<int>>&adj, vector<vector<int>>&rec){
        vector<int>t(26, 0), h;
        
        rec[curr] = vector<int>(1, -1);
        
        for(auto itr: adj[curr]){
            
            if(rec[itr].size() == 1){
                return {-1};
            }else if(rec[itr].size() == 26){
                h = rec[itr];
            }else{
                h = dfs(itr, c, adj, rec);
            }
            
            if(h.size() == 1){
                return h;
            }
            
            for(int i=0;i<26;i++){
                if(h[i] > t[i]){
                    t[i] = h[i];
                }
            }
        }
        
        t[ (int)c[curr] - 97 ]++;
        rec[curr] = t;
        
        return t;
    }
};