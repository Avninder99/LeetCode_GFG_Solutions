//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
        int pLen = p.length(), sLen = s.length();
        vector<vector<bool>>dp(pLen + 1, vector<bool>(sLen + 1, false));
        dp[0][0] = true;
        for(int i=1;i<=pLen;i++){
            for(int j=0;j<=sLen;j++){
                if(j == 0){
                    if(p[i - 1] == '*'){
                        dp[i][j] = dp[i - 1][j];
                    }else{
                        dp[i][j] = false;
                    }
                }
                else if(p[i - 1] == s[j - 1] || p[i - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[pLen][sLen];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends