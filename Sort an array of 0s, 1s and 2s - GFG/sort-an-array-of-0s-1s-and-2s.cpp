// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
        int rptr=0, bptr=n-1;
        int i=0;
        while(i<n && a[i] == 0){
            rptr++;
            i++;
        }
        i=n-1;
        
        while(i>=0 && a[i] == 2){
            bptr--;
            i--;
        }
        
        i=rptr;
        while(i<=bptr && rptr <= bptr){
            if(a[i] == 0){
                a[i] = a[rptr];
                a[rptr] = 0;
                rptr++;
                i++;
            }else if(a[i] == 2){
                a[i] = a[bptr];
                a[bptr] = 2;
                bptr--;
            }else{
                i++;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends