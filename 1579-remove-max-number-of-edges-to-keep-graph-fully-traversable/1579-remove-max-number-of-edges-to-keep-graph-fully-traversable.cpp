class DSU {     // This has both union by rank and union by size functionality
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
        bool connected(int n1, int n2){
            return findUParent(n1) == findUParent(n2);
        }
        bool gConnected(){
            int init = findUParent(1);
            for(int i=1;i<N;i++){
                if(findUParent(i) != init){
                    return false;
                }
            }
            return true;
        }
};
bool cmp(vector<int>&a, vector<int>&b){
    return a[0] > b[0];
}
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        sort(e.begin(), e.end(), cmp);
        DSU setA(n), setB(n);
        int lenE = e.size(), count = 0;
        for(int i=0;i<lenE;i++){
            if(e[i][0] == 3){
                if( setA.connected(e[i][1], e[i][2]) ){
                    count++;
                }else{
                    setA.unionBySize({e[i][1], e[i][2]});
                    setB.unionBySize({e[i][1], e[i][2]});
                }
            }else if(e[i][0] == 1){
                if( setA.connected(e[i][1], e[i][2]) ){
                    count++;
                }else{
                    setA.unionBySize({e[i][1], e[i][2]});
                }
            }else{
                if( setB.connected(e[i][1], e[i][2]) ){
                    count++;
                }else{
                    setB.unionBySize({e[i][1], e[i][2]});
                }
            }
        }

        if(setA.gConnected() && setB.gConnected()){
            return count;
        }
        return -1;
    }
};