class Solution {
public:
    vector<int> answerQueries(vector<int> n, vector<int>& q) {
        sort(n.begin(), n.end());
        vector<int>res;
        for (int i=1; i<n.size(); ++i){
            n[i] += n[i-1];
        }
        for (int& itr: q){
            res.push_back(upper_bound(n.begin(), n.end(), itr) - n.begin());
        }
        return res;
    }
};