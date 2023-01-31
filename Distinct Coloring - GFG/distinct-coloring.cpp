//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long int>>rec;
        for(int i=0;i<N;i++){
            rec.push_back({r[i], g[i], b[i]});
        }
        for(int i=N-2;i>=0;i--){
            rec[i][0] = rec[i][0] + min(rec[i+1][1], rec[i+1][2]);
            rec[i][1] = rec[i][1] + min(rec[i+1][0], rec[i+1][2]);
            rec[i][2] = rec[i][2] + min(rec[i+1][0], rec[i+1][1]);
        }
        long long int mini = LLONG_MAX;
        for(int i=0;i<3;i++){
            if(rec[0][i] < mini) mini = rec[0][i];
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends