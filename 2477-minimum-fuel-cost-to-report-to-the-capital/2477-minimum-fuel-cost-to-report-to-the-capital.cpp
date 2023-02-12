class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& r, int s) {
        vector<vector<int>>adj(r.size() + 1);
        for(auto itr: r){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        long long fCost = 0;
        traverser(0, adj, s, -1, fCost);
        return fCost;
    }
private:
    long long traverser(int curr, vector<vector<int>>&adj, int &s, int p, long long &fCost){
        long long sum = 1, res;
        for(auto itr: adj[curr]){
            if(itr != p){
                sum += traverser(itr, adj, s, curr, fCost);
            }
        }
        if(curr != 0){
            res = sum/s;
            if(sum % s != 0){
                res++;
            }
            fCost += res;
        }
        return sum;
    }
};