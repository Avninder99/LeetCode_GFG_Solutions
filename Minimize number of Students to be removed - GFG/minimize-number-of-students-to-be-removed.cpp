//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> dp;
        for(int i=0;i<N;i++){
            int x = H[i];
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if(it == dp.end()){
                dp.push_back(x);
            }
            else{
                *it=x;
            }
        }
        return N - dp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends