//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // DFS approach
    // int dfs(string &s, string &t, vector<string>&w, int count, string prev, vector<int>&vis, int &ws, int &tl){
    //     if(s == t) return 1;
    //     else if(count > ws){
    //         return 10001;
    //     }
    //     int temp = 10001;
    //     for(int i=0;i<ws;i++){
    //         string itr = w[i];
    //         if(vis[i] == 1) continue;
    //         int diff = 0;
    //         for(int j=0;j<tl;j++){
    //             if(t[j] != itr[j]){
    //                 diff++;
    //             }
    //         }
    //         if(diff == 1){
    //             vis[i] = 1;
    //             temp = min(temp, dfs(s, itr, w, count + 1, t, vis, ws, tl));
    //             vis[i] = 0;
    //         }
    //     }
    //     return temp + 1;
    // }
    int wordLadderLength(string s, string t, vector<string>& w) {
        // Code here
        if(s == t) return 0;
        
        bool sExist = false, tExist = false;
        for(auto itr: w){
            if(itr == s){
                sExist = true;
            }else if(itr == t){
                tExist = true;
            }
        }
        if(!tExist) return 0;
        if(!sExist) w.push_back(s);
        
        int change = 1, ws = w.size(), tl = t.length();
        vector<int>vis(ws, 0);
        
        // int res = dfs(s, t, w, 0, t, vis, ws, tl);
        // if(res >= 10000){
        //     return 0;
        // }
        // return res;
        
        
        // BFS approach
        queue<string>q1;
        q1.push(t);
        q1.push("1");
        
        while(q1.size() > 1 && change <= w.size()){
            string holder = q1.front();
            q1.pop();
            if(holder == s) return change;
            if(holder == "1"){
                change++;
                q1.push("1");
                continue;
            }
            
            for(int i=0;i<ws;i++){
                if(vis[i] == 1) continue;
                
                int diff = 0;
                string itr = w[i];
                
                for(int j=0;j<tl;j++){
                    if(holder[j] != itr[j]){
                        diff++;
                    }
                }
                
                if(diff == 1){
                    vis[i] = 1;
                    q1.push(itr);
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends