class DSU {     // This has both union by rank and union by size functionality
    private:
        vector<int>rank, parent, size;
        int N;
    public:
        DSU(int len){
            N = len;
            size = vector<int>(len, 1);
            parent = vector<int>(len);
            for(int i=0;i<len;i++){
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
        void parentPrinter(){
            for(int i=0;i<N;i++){
                cout << parent[i] << " ";
            }
            cout << endl;
            return;
        }
        void sizePrinter(){
            for(int i=0;i<N;i++){
                cout << size[i] << " ";
            }
            cout << endl;
            return;
        }
};
bool cmp(vector<int>&a, vector<int>&b){
    return a[2] < b[2];
}
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        
        int lenQ = q.size(), lenE = e.size();
        for(int i=0;i<q.size();i++){
            q[i].push_back(i);
        }
        
        sort(e.begin(), e.end(), cmp);
        sort(q.begin(), q.end(), cmp);
        
        DSU myDSU(n);
        int eptr = 0, qptr = 0;
        bool rec = false;
        vector<bool>res(lenQ, false);
        
        while(qptr < lenQ){
            while(eptr < lenE && e[eptr][2] < q[qptr][2]){
                myDSU.unionBySize({e[eptr][0], e[eptr][1]});
                eptr++;
            }
            // check via union whether nodes are connected or not
            rec = myDSU.connected(q[qptr][0], q[qptr][1]);
            res[q[qptr][3]] = rec;
            qptr++;
        }
        return res;
    }
};