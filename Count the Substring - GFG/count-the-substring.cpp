//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  long long countSubstring(string S){
    int n =S.length();
    long long ans =0;
    int sum =0,onsekam=0;
    unordered_map<int,int> mm;
    for(auto x:S)
    {
        if(x=='1')sum++;else sum--;
        if(sum<=0)onsekam++;
        mm[sum]++;
    }
    sum=0;
    for(int i=0;i<n;i++)
    {
        ans+=(n-i-onsekam);
        if(S[i]=='1')
        {
            sum++;
            mm[sum]--;
            onsekam+=mm[sum];
        }
        else{
            sum--;
            mm[sum]--;
            onsekam--;
            onsekam-=mm[sum+1];
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends