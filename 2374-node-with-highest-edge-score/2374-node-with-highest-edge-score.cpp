class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long int maxi = 0;
        int ed;
        unordered_map<int, long long int>rec;
        for(int i=0;i<edges.size();i++){
            rec[edges[i]] += i;
            if(rec[edges[i]] > maxi){
                maxi = rec[edges[i]];
                ed = edges[i];
            }else if(rec[edges[i]] == maxi){
                ed = min(ed, edges[i]);
            }
        }
        return ed;
    }
};