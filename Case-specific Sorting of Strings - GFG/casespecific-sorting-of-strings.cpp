//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        // priority_queue<char, vector<char>, greater<char>>lc, uc;
        string res, lc, uc;
        int lptr = 0, uptr = 0;
        for(char itr: str){
            if((int)itr >= 97){
                lc += itr;
            }else{
                uc += itr;
            }
        }
        sort(lc.begin(), lc.end());
        sort(uc.begin(), uc.end());
        for(int i=0;i<n;i++){
            if((int)str[i] >= 97){
                res += lc[lptr++];
            }else{
                res += uc[uptr++];
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends