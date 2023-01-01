//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int m = 1e9+7;
	long long pow(long long b,long long e,long long m)
	{
	    long long r=1;
	    while(e)
	    {
	        if(e%2)r=r%m * b%m; r%=m;
	        b=b%m * b%m; b%=m;
	        e/=2;
	    }
	    return r;
	}
	long long modinv(long long n)
	{
	    return pow(n,m-2,m);
	}
	int compute_value(int n)
	{
	    // Code here
	    long long r=1;
    	long long p=1;
    	
    	for(int i=1;i<=n;i++)
    	{
    	    p=p%m*(n-i+1)%m*modinv(i)%m;
    	    p%=m;
    	    r+= p%m * p%m;
    	    r%=m;
    	}
    	return r;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends