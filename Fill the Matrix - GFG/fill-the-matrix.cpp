//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<int>dist;
        dist.push_back(abs(1-x) + abs(1-y));    // Top-Left
        dist.push_back(abs(1-x) + abs(M-y));    // Top-Right
        dist.push_back(abs(N-x) + abs(1-y));    // Bottom-Left
        dist.push_back(abs(N-x) + abs(M-y));    // Bottom-Right
        return *max_element(dist.begin(), dist.end());
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends