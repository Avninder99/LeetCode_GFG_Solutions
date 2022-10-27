//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    vector<long long>v1;
    void func(int len, int l, long long num, long long &ul){
        if(l > len) return;
        
        if(l != 1 && num <= ul) v1.push_back(num);
        int ld = num%10;
        if(num*10 > ul) return;
        if(ld < 9){
            func(len, l+1, (num*10 + (ld+1)), ul);
        }
        if(ld > 0){
            func(len, l+1, (num*10 + (ld-1)), ul);
        }
        return;
    }
    vector<long long> absDifOne(long long N)
    {
        string s1 = to_string(N);
        int len = s1.length(), counter=0;
        //code here.
        if(len == 1){
            v1.push_back(-1);
            return v1;
        }
        for(int i=1;i<10;i++){
            func(len, 1, i, N);
        }
        sort(v1.begin(), v1.end());
        return v1;
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            long long n;
            cin>>n;
            Solution ob;
            vector<long long> res = ob.absDifOne(n);
            for(int i = 0;i<res.size();i++)
                cout<<res[i]<<" ";
            if(res.size()==0)
                cout<<-1;
            cout<<endl;    
        }
}

// } Driver Code Ends