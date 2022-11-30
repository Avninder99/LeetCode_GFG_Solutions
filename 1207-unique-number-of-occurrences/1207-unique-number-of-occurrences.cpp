class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>m1;
        unordered_set<int>s1;
        for(int i=0;i<arr.size();i++){
            m1[arr[i]]++;
        }
        for(auto itr: m1){
            int o = s1.size();
            s1.insert(itr.second);
            if(o == s1.size()){
                return false;
            }
        }
        return true;
    }
};