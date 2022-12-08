//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int k) {
    vector<long long>res(N-(k-1), 0);
    queue<int>q1;
    for(int i=0;i<k;i++){
        if(A[i] < 0){
            q1.push(i);
        }
    }
    if(!q1.empty()) res[0] = A[q1.front()];
    int lptr=0, rptr=k-1;
    for(int i=1; i<N && rptr < N-1; i++){
        lptr++;
        if(!q1.empty() && q1.front() < lptr){
            q1.pop();
        }
        
        rptr++;
        if(A[rptr] < 0){
            q1.push(rptr);
        }
        
        if(q1.empty()){
            res[lptr] = 0;
        }else{
            res[lptr] = A[q1.front()];
        }
        
        
    }
    return res;
}