class Solution {
public:
    bool canConstruct(string r, string m) {
        if(m.length() < r.length()) return false;
        vector<int>rec(26, 0);
        for(char c: m){
            rec[(int)c - 97]++;
        }
        for(char c: r){
            if(!(rec[(int)c - 97]--)){
                return false;
            }
        }
        return true;
    }
};