class Solution {
public:
    int dfs(int curr, string &s, vector<vector<int>>&children, int &maxi){
        int t = 0, m1 = 0, m2 = 0;
        for(int itr: children[curr]){
            t = dfs(itr, s, children, maxi);
            if(s[itr] != s[curr]){
                if(t >= m1){
                    m2 = m1;
                    m1 = t;
                }else if(t > m2){
                    m2 = t;
                }
            }
        }
        maxi = max(maxi, (m1 + m2 + 1));
        return m1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>children(parent.size()+1);
        for(int i=1;i<parent.size();i++){
            children[parent[i]].push_back(i);
        }
        int maxi = 0;
        dfs(0, s, children, maxi);
        return maxi;
    }
};