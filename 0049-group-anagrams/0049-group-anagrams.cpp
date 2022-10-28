class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m1;
        vector<vector<string>>v1;
        
        int size = strs.size();
        string s2;
        
        for(int i=0;i<size;i++){
            s2 = strs[i];
            sort(s2.begin(), s2.end());
            m1[s2].push_back(strs[i]);
        }
        
        for(auto itr : m1){
            v1.push_back(itr.second);
        }
        
        return v1;
    }
};