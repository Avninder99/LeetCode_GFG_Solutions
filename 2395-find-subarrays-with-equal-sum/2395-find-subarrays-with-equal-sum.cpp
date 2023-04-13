class Solution {
public:
    bool findSubarrays(vector<int>& n) {
        int len = n.size();
        unordered_set<long long int>s1;
        for(int i=0;i<len-1;i++){
            long long int sum = n[i] + n[i + 1];
            if(s1.count(sum) > 0){
                return true;
            }
            s1.insert(sum);
        }
        return false;
    }
};