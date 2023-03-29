//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        int count = 0, res = 0;
        // lower -> --, upper -> ++
        for(int i=0;i<s.length();i++){
            count = 0;
            for(int j=i;j<s.length();j++){
                if((int)s[j] < 95){
                    count++;
                }else{
                    count--;
                }
                if(count == 0){
                    res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends