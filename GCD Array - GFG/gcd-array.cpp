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
    int solve(int N, int K, vector<int> &arr) {
        // code here
        long long int sum = 0;
        vector<int>fac;
        for(int i=1;i<N;i++){
            arr[i] += arr[i - 1];
        }
        sum = arr[N - 1];
        for(int i=1;i*i<=sum;i++){
            if(sum%i == 0){
                fac.push_back(i);
                if(i != sum/i){
                    fac.push_back(sum/i);
                }
            }
        }
        sort(fac.begin(), fac.end(), greater<int>());
        int count;
        for(int i=0;i<fac.size();i++){
            count = 0;
            for(int j=0;j<N;j++){
                if(arr[j]%fac[i] == 0){
                    count++;
                }
            }
            if(count >= K){
                return fac[i];
            }
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends