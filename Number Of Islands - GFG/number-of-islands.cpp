//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
        int counter(int rs, vector<vector<int>>&g){
            for(int i=1;i<N;i++){
                findUParent(i);
            }
            unordered_set<int>s1;
            s1.clear();
            for(int i=1;i<N;i++){
                int c = (i-1)/rs, r = (i-1)%rs;
                if(g[c][r] < 0){
                    s1.insert(parent[i]);
                }
            }
            return s1.size();
        }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        DSU myDSU((n * m));
        vector<vector<int>>g(n, vector<int>(m, 0));
        int val = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                g[i][j] = val++;
            }
        }
        vector<vector<int>>dirc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<int>res;
        for(auto itr: op){
            int c = itr[0], r = itr[1];
            if(g[c][r] > 0){
                for(int i=0;i<4;i++){
                    int nc = c + dirc[i][0], nr = r + dirc[i][1];
                    if(nc < 0 || nr < 0 || nc >= n || nr >= m || g[nc][nr] >= 0){
                        continue;
                    }
                    myDSU.unionBySize({g[c][r], g[nc][nr] * -1});
                }
                g[c][r] *= -1;
            }
            res.push_back(myDSU.counter(m, g));
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends