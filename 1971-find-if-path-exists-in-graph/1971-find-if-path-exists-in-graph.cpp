class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        if(n == 1) return true;
        vector<vector<int>>rec(n);
        vector<int>visited(n, 0);
        queue<int>q1;
        for(auto itr: e){
            rec[itr[0]].push_back(itr[1]);
            rec[itr[1]].push_back(itr[0]);
        }
        q1.push(s);
        while(!q1.empty()){
            for(auto itr: rec[q1.front()]){
                cout << itr;
                if(itr == d) return true;
                else if(!visited[itr]){
                    q1.push(itr);
                    visited[itr] = 1;
                }
            }
            q1.pop();
        }
        return false;
    }
};