class Solution {
public:
    unordered_map<int, unordered_set<int>> out, in;
    int ans = 0;
    
    void dfs(int node) {
        for (int x: out[node]) {
            // There is an edge (node->x). We must reverse it.
            ans++; 
			// delete, edge (x <- node)
            in[x].erase(node);
			// recurse.
            dfs(x);
        }
        for (int x:in[node]) {
		    // The edge is (x <- node). So delete (node -> x).
			out[x].erase(node);
			// recurse.
            dfs(x);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
		// make graph.
        for (auto x: connections) {
            out[x[0]].insert(x[1]);
            in[x[1]].insert(x[0]);
        }
		// start with node 0.
        dfs(0);
        return ans;
    }
};