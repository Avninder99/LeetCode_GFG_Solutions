class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<vector<int>>adj(g.size());
        for(int i=0;i<g.size();i++){
            for(auto itr: g[i]){
                adj[itr].push_back(i);
            }
        }
        
        vector<int>inDeg(g.size(), 0);
        for(int i=0;i<g.size();i++){
            inDeg[i] = g[i].size();
        }
        
        queue<int>rec;
        vector<int>res;
        for(int i=0;i<g.size();i++){
            if(inDeg[i] == 0){
                rec.push(i);
                res.push_back(i);
            }
        }
        while(!rec.empty()){
            int holder = rec.front();
            rec.pop();
            
            for(auto itr: adj[holder]){
                if(--inDeg[itr] == 0){
                    rec.push(itr);
                    res.push_back(itr);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};