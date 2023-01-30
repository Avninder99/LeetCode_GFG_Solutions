//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int countVertex(int N, vector<vector<int>>e){
        // code here
        vector<vector<int>>adj(N+1);
        for(auto itr: e){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        pair<int, int>holder = dfs(1, -1, adj);
        return min(holder.first, holder.second);
    }
  private:
    pair<int, int> dfs(int curr, int parent, vector<vector<int>>&adj){
        pair<int, int>rec;
        int psum = 1, nsum = 0;
        for(auto itr: adj[curr]){
            if(itr != parent){
                rec = dfs(itr, curr, adj);
                psum += min(rec.first, rec.second);
                nsum += rec.first;
            }
        }
        rec = make_pair(psum, nsum);
        return rec;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends