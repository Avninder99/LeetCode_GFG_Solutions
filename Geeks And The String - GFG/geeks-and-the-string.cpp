//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        deque<char>dq;
        for(int i=0;i<s.length();i++){
            if(dq.empty() || dq.back() != s[i]){
                dq.push_back(s[i]);
            }else{
                dq.pop_back();
            }
        }
        s = "";
        while(!dq.empty()){
            s += dq.front();
            dq.pop_front();
        }
        if(s.length() > 0){
            return s;
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends