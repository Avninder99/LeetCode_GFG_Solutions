//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // a - 1, b - 1, l - 2, n - 1, o - 2
    int maxInstance(string s){
        if(s.length() < 7) return 0;
        vector<int>rec(26, 0);
        for(char itr: s){
            rec[(int)itr - 97]++;
        }
        int occurances = min(rec[0], min(rec[1], min(rec[11]/2, min(rec[13], rec[14]/2))));
        return occurances;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends