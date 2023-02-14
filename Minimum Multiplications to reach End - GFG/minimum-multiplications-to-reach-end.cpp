//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>rec(1000000, 0);
        queue<int>q1;
        q1.push(start);
        q1.push(-1);
        int steps = 0;
        
        while(q1.size() > 1){
            int holder = q1.front();
            q1.pop();
            
            if(holder == -1){
                steps++;
                q1.push(-1);
                continue;
            }
            
            if(holder == end) return steps;
            
            for(int itr: arr){
                int t = (holder * itr) % 100000;
                if(rec[t] == 1) continue;
                rec[t] = 1;
                q1.push(t);
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends