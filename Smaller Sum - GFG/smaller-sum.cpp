//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long>res;
        unordered_map<int, long long>m1;
        vector<int>rec = arr;
        sort(rec.begin(), rec.end());
        
        long long sum = rec[0];
        m1[rec[0]] = 0;
        for(int i=1;i<n;i++){
            if(rec[i] != rec[i - 1]){
                m1[rec[i]] = sum;
            }
            sum += rec[i];
        }
        for(auto itr: arr){
            res.push_back(m1[itr]);
        }
        return res;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends