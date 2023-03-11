//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        unordered_map<int, int>freqRec;
        vector<int>rec(N, 1), res;
        for(int i=N-1;i>=0;i--){
            if(freqRec.find(A[i]) == freqRec.end()){
                freqRec[A[i]] = 1;
            }else{
                freqRec[A[i]]++;
                rec[i] = freqRec[A[i]];
            }
        }
        for(auto itr: Q){
            int counter = 0;
            for(int i=itr[0];i<=itr[1];i++){
                if(rec[i] == itr[2]){
                    counter++;
                }
            }
            res.push_back(counter);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends