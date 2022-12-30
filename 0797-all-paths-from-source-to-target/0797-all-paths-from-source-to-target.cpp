class Solution {
public:
    void dfs(int node, vector<vector<int>>&g, vector<int>rec, vector<vector<int>>&res){
        rec.push_back(node);
        if(node == g.size() - 1){
            res.push_back(rec);
        }
        for(auto itr: g[node]){
            dfs(itr, g, rec, res);
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>>res;
        vector<int>rec;
        dfs(0, g, rec, res);
        return res;
    }
};