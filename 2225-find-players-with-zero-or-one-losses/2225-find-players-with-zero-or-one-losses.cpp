class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        map<int, pair<int,int>>rec;     // map instead of unordered_map because it is sorted
        for(auto itr: m){
            rec[itr[0]].first++;
            rec[itr[1]].second++;
        }
        
        vector<vector<int>>res(2, vector<int>(0));
        
        for(auto itr: rec){
            if(!(itr.second.second)){
                res[0].push_back(itr.first);
            }else if(itr.second.second == 1){
                res[1].push_back(itr.first);
            }
        }
        
        return res;
    }
};