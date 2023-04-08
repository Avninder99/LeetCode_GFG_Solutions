//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>st;
        long long int mul = 1;
        for(auto itr: arr){
            if(st.empty()){
                st.push(itr);
                continue;
            }
            
            if(st.top() == 0 || itr == 0){
                if(st.top() + itr < 0){
                    st.pop();
                }else{
                    st.push(itr);
                }
            }else{
                mul = (long long int)st.top() * itr;
                if(mul < 0){
                    st.pop();
                }else{
                    st.push(itr);
                }
            }
        }
        
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
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

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends