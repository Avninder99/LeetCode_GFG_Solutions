//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class myDSU {
    private:
        vector<int>parent, size;
        int N = 0;
    public:
        myDSU(int len){
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
        bool connected(vector<int>pair){
            return findUParent(pair[0]) == findUParent(pair[1]);
        }
        int numberOfSets(){
            int count = 0;
            for(int i=0;i<N;i++){
                if(parent[i] == i){
                    count++;
                }
            }
            return count;
        }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        myDSU s1(n);
        int redundantEdges = 0;
        for(auto itr: edge){
            if(s1.connected(itr)){
                redundantEdges++;
            }else{
                s1.unionBySize(itr);
            }
        }
        int graphsNum = s1.numberOfSets();
        if(graphsNum - 1 > redundantEdges) return -1;
        return graphsNum - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends