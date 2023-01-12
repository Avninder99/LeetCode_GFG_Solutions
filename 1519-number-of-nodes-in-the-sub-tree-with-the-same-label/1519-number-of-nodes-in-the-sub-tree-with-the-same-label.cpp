class Solution {
public:
    int * dfs(int curr, vector<vector<int>>&adj, vector<int>&rec, int parent, string &l){
        int holder[26] = {0};
        int *t;
        for(int itr=0; itr < adj[curr].size(); itr++){
            if(adj[curr][itr] != parent){
                t = dfs(adj[curr][itr], adj, rec, curr, l);
                for(int i=0;i<26;i++){
                    holder[i] += t[i];
                }
            }
        }
        rec[curr] = ++holder[(int)l[curr] - 97];
        return holder;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        vector<int>rec(n, 1);
        int count = 0;
        for(auto itr: edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        dfs(0, adj, rec, -1, labels);
        return rec;
    }
};