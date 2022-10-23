class Solution {
public:
    vector<int> findErrorNums(vector<int>& n) {
        unordered_set<int>s1;
        int gsum = 0, esum = ( n.size() * (n.size() + 1) ) / 2, tsum = 0;
        for(int i=0;i<n.size();i++){
            s1.insert(n[i]);
            tsum += n[i];
        }
        for(auto itr:s1) gsum += itr;
        
        int missed_num = esum - gsum;
        
        int dup_num = (tsum + missed_num) - esum;
        
        vector<int>v1 = {dup_num, missed_num};
        
        return v1;
    }
};