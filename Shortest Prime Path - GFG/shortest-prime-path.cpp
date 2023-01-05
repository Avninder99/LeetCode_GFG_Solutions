//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  vector<int> prime;
  
  Solution(){
      prime.assign(10000,1);
      
      prime[1]=0;
      for(int i=2;i<10000;i++)
      {
          for(int j=2*i;j<10000;j+=i )
          {
              prime[j]=0;
          }
      }
  }
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        vector<int> visited(10000,-1);
        
        queue<int> q;
        q.push(Num1),visited[Num1]=0;
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            
            string s= to_string(x);
            
            for(int i=0;i<4;i++)
            {
                string t=s;
                int start =(i==0?1:0);
                for(int d=start;d<10;d++)
                {
                    t[i]='0'+d;
                    int y=stoi(t);
                    if(prime[y] && visited[y] ==-1)
                    {
                        visited[y]=1+visited[x];
                        q.push(y);
                    }
                    
                }
            }
        }
        return visited[Num2];
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends