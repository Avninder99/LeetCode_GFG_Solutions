//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        unordered_set<int>s1;
        int dCount = 0;
        if(S[0] == S[1]){
            s1.insert(0);
            dCount++;
        }
        if(S[N - 1] == S[N - 2]){
            s1.insert(N - 1);
        }
        for(int i=1;i<N - 1;i++){
            if(S[i] == S[i + 1]){
                s1.insert(i);
                dCount++;
            }else if(S[i] == S[i - 1]){
                s1.insert(i);
            }
        }
        if(dCount == 0) return 0;
        int i;
        for(i=0;i<N;i++){
            int ind = P[i];
            if(s1.find(ind - 1) != s1.end() && S[ind - 1] == S[ind]){
                dCount--;
            }
            if(s1.find(ind + 1) != s1.end() && S[ind + 1] == S[ind]){
                dCount--;
            }
            s1.erase(ind);
            if(dCount == 0){
                break;
            }
        }
        return i + 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends