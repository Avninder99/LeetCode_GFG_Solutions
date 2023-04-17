class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        vector<bool>res;
        int maxi = *max_element(c.begin(), c.end());
        for(auto itr: c){
            res.push_back(itr + e >= maxi);
        }
        return res;
    }
};