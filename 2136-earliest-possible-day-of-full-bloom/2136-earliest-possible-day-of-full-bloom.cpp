bool cmp(vector<int>&a, vector<int>&b){
    if(a[1] == b[1]) return a[0] > b[0];
    return a[1] > b[1];
}
class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<vector<int>>v1;
        for(int i=0;i<p.size();i++){
            v1.push_back({p[i], g[i]});
        }
        sort(v1.begin(), v1.end(), cmp);
        int ed=0, fp=-1, maxd=-1;
        for(int i=0;i<p.size();i++){
            fp += v1[i][0];
            ed = fp + v1[i][1] + 1;
            maxd = max(maxd, ed);
        }
        return maxd;
    }
};