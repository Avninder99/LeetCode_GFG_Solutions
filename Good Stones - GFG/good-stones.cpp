//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int goodStones(int n, vector<int> &arr){
        // Code here
        vector<int>records(n, -1);
        // -1 -> not marked, 0 -> loop, 1 -> waiting, 2 -> safe
        for(int i=n-1;i>=0;i--){
            if(records[i] == -1){
                records[i] = dfs(i, arr, records, n);
            }
        }
        int count = 0;
        for(int itr: records){
            if(itr == 2) count++;
        }
        return count;
    }
private:
    int dfs(int currIndex, vector<int>&arr, vector<int>&records, int &n){
        int nIndex = currIndex + arr[currIndex];
        if(nIndex < 0 || nIndex >= n || records[nIndex] == 2){
            return 2;
        }else if(records[nIndex] == 1 || records[nIndex] == 0){
            return 0;
        }
        records[currIndex] = 1;
        records[currIndex] = dfs(nIndex, arr, records, n);
        return records[currIndex];
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends