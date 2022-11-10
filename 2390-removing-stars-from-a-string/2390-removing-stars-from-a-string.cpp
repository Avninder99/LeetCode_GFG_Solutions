class Solution {
public:
    string removeStars(string s) {
        string res;
        int len1 = s.length();
        for(int i=0;i<len1;i++){
            if(res.length() > 0 && s[i] == '*' && res[res.length() - 1] != '*'){
                res.pop_back();
            }else{
                res += s[i];
            }
        }
        return res;
    }
};