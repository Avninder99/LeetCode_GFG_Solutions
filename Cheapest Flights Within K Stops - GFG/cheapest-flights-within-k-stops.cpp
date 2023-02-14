//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int, int>>>adj(n);   // from -> { {to, stopNum}, ... }
        vector<int>records(n, 1e7);  // cost till now
        
        for(auto itr: flights){
            adj[itr[0]].push_back({itr[1], itr[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;   // {stopNum, cost, node}
        
        pq.push({0, 0, src});
        
        while(!pq.empty()){
            vector<int>holder = pq.top();
            pq.pop();
            
            if(holder[0] > K + 1){
                return -1;
            }
            
            if(holder[0] == K + 1){
                if(holder[2] == dst){
                    records[dst] = min(records[dst], holder[1]);
                }
                continue;
                // why i am not returning -1 if not dst ?
                // because many entries in pq may have holder[0] == k+1 from 
                // which anyone could contain destination node
                // so we need to check them all after it the first if condition can hold the overflow
            }
            
            for(auto itr: adj[holder[2]]){
                int newCost = holder[1] + itr.second;
                if(records[itr.first] > newCost){
                    records[itr.first] = newCost;
                    pq.push({holder[0] + 1, newCost, itr.first});
                }
            }
        }
        return records[dst] == 1e7 ? -1 : records[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends