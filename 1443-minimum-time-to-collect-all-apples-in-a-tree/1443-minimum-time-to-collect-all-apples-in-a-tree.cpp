class Solution {
public:
    int dfs(int curr, vector<vector<int>>&adj, vector<vector<int>>&rec, int parent, vector<bool>&h){
        int total = 0;
        for(auto itr: adj[curr]){
            int t = 0;
            if(itr != parent){
                t += dfs(itr, adj, rec, curr, h);
                total += t;
            }
            rec[curr].push_back(t);
        }
        if(h[curr]){
            total++;
        }
        return total;
    }
    void search(int curr, vector<vector<int>>&adj, vector<vector<int>>&rec, int parent, int &count){
        for(int i=0; i<adj[curr].size(); i++){
            if(rec[curr][i] > 0){
                count++;
                search(adj[curr][i], adj, rec, curr, count);
            }
        }
        if(curr) count++;
        return;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& h) {
        vector<vector<int>>adj(n), rec(n);
        int count = 0;
        for(auto itr: edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
        // for filling rec vector which will tell us if a subtree consists of apples or not
        dfs(0, adj, rec, -1, h);
        
        // finding the nodes with apple and only going on a path
        // if a node contains an apple down the path on it
        // for this we have rec vector which holds all the info like
        // if a child subtree has a node that contains an apple or not
        search(0, adj, rec, -1, count);
        return count;
    }
};