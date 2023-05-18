class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<int>indegree(n, 0), res;
        for(auto itr: e){
            indegree[itr[1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};