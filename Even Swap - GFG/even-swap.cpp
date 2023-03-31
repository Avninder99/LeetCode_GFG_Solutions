//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            vector<int>res(a);
            int l = 0;
            if(res[n - 1]%2){
                res.push_back(2);
            }else{
                res.push_back(1);
            }
            for(int i=1;i<n+1;i++){
                if(res[i]%2 == res[l]%2){
                    continue;
                }else{
                    sort(res.begin()+l, res.begin()+(i), greater<int>());
                    l = i;
                }
            }
            res.pop_back();
            return res;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends