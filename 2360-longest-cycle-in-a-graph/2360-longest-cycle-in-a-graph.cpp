class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int maxi = -1, len = edges.size();
        queue<int>q1;
        vector<int>indRec(len, 0);
        for(auto itr: edges){
            if(itr > -1) indRec[itr]++;
        }
        
        for(int i=0;i<len;i++){
            if(indRec[i] == 0){
                q1.push(i);
            }
        }
        
        while(!q1.empty()){
            int holder = q1.front();
            q1.pop();
            
            if(edges[holder] > -1 && --indRec[edges[holder]] == 0){
                q1.push(edges[holder]);
            }
        }
        
        for(int i=0;i<len;i++){
            if(indRec[i]){
                maxi = max(maxi, dfs(i, edges, indRec));
            }
        }
        return maxi;
    }
private:
    int dfs(int curr, vector<int>&e, vector<int>&indRec){
        if(indRec[e[curr]] == 0) return 1;
        indRec[curr] = 0;
        return dfs(e[curr], e, indRec) + 1;
    }
};