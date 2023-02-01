//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> E)
  {
    // code here
    vector<int>indRec(N, 0);
    for(int itr: E){
        if(itr > -1) indRec[itr]++;
    }
    
    queue<int>q1;
    for(int i=0;i<N;i++){
        if(indRec[i] == 0) q1.push(i);
    }
    
    while(!q1.empty()){
        int holder = q1.front();
        q1.pop();
        
        if(E[holder] > -1 && --indRec[E[holder]] == 0){
            q1.push(E[holder]);
        }
    }
    
    long long sum = 0, maxi = -1;
    for(int i=0;i<N;i++){
        if(indRec[i] == 1){
            maxi = max(maxi, dfs(i, indRec, E));
        }
    }
    return maxi;
  }
  private:
    long long dfs(int curr, vector<int>&indRec, vector<int>&E){
        if(indRec[curr] == 0) return 0;
        indRec[curr] = 0;
        return dfs(E[curr], indRec, E) + curr;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends