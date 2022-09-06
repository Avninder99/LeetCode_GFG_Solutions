class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>m1;
        unordered_set<char>s1;
        int len1 = s.length(), len2 = t.length();
        if(len1 != len2) return false;
        for(int i=0;i<len1;i++){
            auto itr = m1.find(s[i]);
            if(itr == m1.end()){
                if(s1.count(t[i])) return false;
                m1[s[i]] = t[i];
                s1.insert(t[i]);
            }else{
                if(itr->second != t[i]) return false;
            }
        }
        return true;
    }
};