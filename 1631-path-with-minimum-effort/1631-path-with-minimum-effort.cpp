class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int cs = h.size(), rs = h[0].size();
        vector<vector<int>>g(cs, vector<int>(rs, 1e7));
        
        g[0][0] = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        // max diff till now on this edge, cVal, rVal
        
        pq.push({0, {0, 0}});
        
        vector<vector<int>>dirc = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        
        while(!pq.empty()){
            
            int eVal = pq.top().first;
            pair<int, int>cd = pq.top().second;
            pq.pop();
            
            if(cd.first == cs - 1 && cd.second == rs - 1){
                return eVal;
            }
            
            for(auto itr: dirc){
                int nc = cd.first + itr[0], nr = cd.second + itr[1];
                
                if(nc < 0 || nr < 0 || nc >= cs || nr >= rs || g[nc][nr] <= max(eVal, abs( h[cd.first][cd.second] - h[nc][nr] ) ) ){
                    continue;
                }
                
                g[nc][nr] = max(eVal, abs( h[cd.first][cd.second] - h[nc][nr] ) );
                
                pq.push({g[nc][nr], {nc, nr}});
                
            }
        }
        return 0;
    }
};