//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        bool breaker = false;
        int aptr = 0, bptr = 0, count = 0, al = A.length(), bl = B.length(), h = ceil(B.length()/A.length())+1;
        
        while(count <= h){
            if(aptr == 0) count++;
            if(bptr == bl - 1 && B[bptr] == A[aptr]){
                return count;
            }
            
            if(A[aptr] == B[bptr]){
                bptr++;
            }
            else if(bptr > 0){
                if(A[aptr] == B[0]){
                    bptr = 1;
                }else{
                    bptr = 0;
                }
            }
            else if(aptr == al - 1){
                break;
            }
            
            aptr = (++aptr)%al;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends