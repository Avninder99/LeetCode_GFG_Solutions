//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int func(string &str, int ptr, int &size, vector<int>&dp){
	        if(ptr < size && str[ptr] == '0'){
	            return 0;
	        }
	        
	        if(ptr >= size - 1){
	            return 1;
	        }
	        
	        if(dp[ptr] == -1){
    	        int one = 0, two = 0;
    	        
    	        if(str[ptr + 1] != '0'){
    	            one = func(str, ptr + 1, size, dp);
    	        }
    	        
    	        string temp = "";
    	        temp += str[ptr];
    	        temp += str[ptr + 1];
    	        
    	        if(stoi(temp) < 27){
    	            two = func(str, ptr + 2, size, dp);
    	        }
    	        
    	        dp[ptr] = (one + two)%1000000007;
	        }
	        
	        return dp[ptr];
	    }
		int CountWays(string str){
		    // Code here
		    if(str[0] == '0') return 0;
		    for(int i=1;i<str.length();i++){
		        if(str[i] == '0' && (str[i - 1] != '1' && str[i - 1] != '2')){
		            return 0;
		        }
		    }
		    int size = str.length(), res;
		    vector<int>dp(size + 1, -1);
		    res = func(str, 0, size, dp);
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends