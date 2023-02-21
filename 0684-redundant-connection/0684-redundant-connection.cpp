class DSU {
    private:
        vector<int>parent, size;
        int N;
    public:
        DSU(int len){
            N = len + 1;
            size = vector<int>(len + 1, 1);
            parent = vector<int>(len + 1);
            for(int i=0;i<len+1;i++){
                parent[i] = i;
            }
        }
        void unionBySize(vector<int>edge){
            int p1 = findUParent(edge[0]), p2 = findUParent(edge[1]);
            if(p1 == p2){
                return;
            }
            int size1 = size[p1], size2 = size[p2];
            if(size1 < size2){
                size[p2] += size[p1];
                parent[p1] = p2;
            }else{
                size[p1] += size[p2];
                parent[p2] = p1;
            }
            return;
        }
        int findUParent(int val){    // compress the path and find the ultimate parent
            if(parent[val] == val){
                return val;
            }else{
                return parent[val] = findUParent(parent[val]);
            }
        }
        bool connected(vector<int>pair){
            return findUParent(pair[0]) == findUParent(pair[1]);
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU s1(edges.size());
        vector<int>res;
        for(auto itr: edges){
            if(s1.connected(itr)){
                res = itr;
            }else{
                s1.unionBySize(itr);
            }
        }
        return res;
    }
};