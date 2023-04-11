//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int len = a + b + c, np, t;
        int arr[3] = {0, 0, 0};
        queue<char>q1;
        for(int i=0;i<len;i++){
            np = -1;
            for(int j=0;j<3;j++){
                if(arr[j] == 2){
                    np = j;
                }
            }
            
            if(np == 0){
                if(!(b || c)){
                    return -1;
                }
                if(b >= c){
                    q1.push('b');
                    b--;
                    arr[1]++;
                }else{
                    q1.push('c');
                    c--;
                    arr[2]++;
                }
            }
            else if(np == 1){
                if(!(a || c)){
                    return -1;
                }
                if(a >= c){
                    q1.push('a');
                    a--;
                    arr[0]++;
                }else{
                    q1.push('c');
                    c--;
                    arr[2]++;
                }
            }
            else if(np == 2){
                if(!(a || b)){
                    return -1;
                }
                if(a >= b){
                    q1.push('a');
                    a--;
                    arr[0]++;
                }else{
                    q1.push('b');
                    b--;
                    arr[1]++;
                }
            }
            else{
                t = max(a, max(b, c));
                if(a == t){
                    q1.push('a');
                    a--;
                    arr[0]++;
                }else if(b == t){
                    q1.push('b');
                    b--;
                    arr[1]++;
                }else{
                    q1.push('c');
                    c--;
                    arr[2]++;
                }
            }
            
            if(q1.size() > 2){
                arr[q1.front() - 97]--;
                q1.pop();
            }
        }
        return len;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends