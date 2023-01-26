//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pr) {
	    // Code here
	    vector<vector<int>>adj(N);
        for(auto itr: pr){
            adj[itr.second].push_back(itr.first);
        }
        
	    vector<int>indRec(N);
	    queue<int>q1;
	    
	    for(int i=0;i<pr.size();i++){
	        indRec[pr[i].first]++;
	    }
	    
	    for(int i=0;i<N;i++){
	        if(indRec[i] == 0){
	            q1.push(i);
	        }
	    }
	    
	    int count = 0;
	    
	    while(!q1.empty()){
	        int holder = q1.front();
	        q1.pop();
	        for(auto itr: adj[holder]){
	            if(--indRec[itr] == 0){
	                q1.push(itr);
	            }
	        }
	       count++;
	    }
	    return count == N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends