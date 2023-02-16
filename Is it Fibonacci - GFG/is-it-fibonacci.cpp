//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GN) {
        // code here
        if(K == 1) return GN[0];
        if(N < K) return GN[N-1];
        int lptr = -1, rptr = K;
        for(int i=1;i<K;i++){
            GN[i] += GN[i-1];
        }
        while(rptr <= N){
            long long prefix_val = 2 * GN[rptr - 1] - (lptr < 0 ? 0 : GN[lptr]);
            GN.push_back(prefix_val);
            rptr++;
            lptr++;
        }
        return GN[N-1] - GN[N-2];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends