//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int, pair<int, int>>m1;
        for(auto itr: lines){
            if(m1.find(itr[0]) == m1.end()){
                m1[itr[0]] = make_pair(0, 0);
            }
            m1[itr[0]].first += 1;
            
            if(m1.find(itr[1]) == m1.end()){
                m1[itr[1]] = make_pair(0, 0);
            }
            m1[itr[1]].second += 1;
        }
        
        int linesNum = 0, maxi = 0;
        for(auto itr = m1.begin(); itr != m1.end(); itr++){
            // cout << itr->first << " -> " << itr->second.first << " - " << itr->second.second << endl; 
            linesNum += itr->second.first;
            maxi = max(maxi, linesNum);
            linesNum -= itr->second.second;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends