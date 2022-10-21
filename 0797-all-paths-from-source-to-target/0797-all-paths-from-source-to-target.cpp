class Solution {
public:
    void func(vector<vector<int>>&g, int ptr, int &n, vector<int>t, vector<vector<int>>&res){
        if(ptr == n-1){
            res.push_back(t);
            return;
        }
        for(int i=0;i<g[ptr].size();i++){
            t.push_back(g[ptr][i]);
            func(g, g[ptr][i], n, t, res);
            t.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>>res;
        vector<int>t;
        t.push_back(0);
        int s = g.size();
        func(g, 0, s, t, res);
        return res;
    }
};