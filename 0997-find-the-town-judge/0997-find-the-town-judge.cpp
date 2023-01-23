class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<vector<int>>v1(n, vector<int>(2, 0));
        for(int i=0;i<t.size();i++){
            v1[t[i][0] - 1][0]++;
            v1[t[i][1] - 1][1]++;
        }
        int ind = -1;
        for(int i=0;i<n;i++){
            if(v1[i][0] == 0){
                if(v1[i][1] == n-1){
                    if(ind != -1) return -1;
                    else ind = i+1;
                }
            }
        }
        return ind;
    }
};