//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int maxVal = arr[N - 1], count = 0;
        vector<int>rec(maxVal + 1, 0);
        unordered_map<int, int>m1;
        
        for(auto itr: arr){
            m1[itr]++;
        }
        
        for(auto itr: arr){
            int inc = m1[itr];
            
            if(rec[itr] < 2){
                for(int i=itr; i<=maxVal; i += itr){
                    rec[i] += inc;
                }
            }
            
            if(rec[itr] > 1){
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends