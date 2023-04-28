class DSU {     // This has both union by rank and union by size functionality
    private:
        vector<int>parent, size;
        int N;
    public:
        DSU(int len){
            N = len;
            size = vector<int>(len, 0);
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
        int gcount(){
            for(int i=0;i<N;i++){
                findUParent(i);
            }
            sort(parent.begin(), parent.end());
            int prev = -1, count = 0;
            for(int i=0;i<N;i++){
                if(parent[i] != prev){
                    count++;
                    prev = parent[i];
                }
            }
            return count;
        }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int len = strs.size();
        DSU myDSU(len);
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(checker(strs[i], strs[j])){
                    myDSU.unionBySize({i, j});
                }
            }
        }
        return myDSU.gcount();
    }
    bool checker(string &s1, string &s2){
        int count = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                count++;
            }
        }
        return count <= 2;
    }
};