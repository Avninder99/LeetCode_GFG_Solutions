class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int len1 = s.length();
        
        for(int i=0;i<len1;i++){
            if(res.length() > 0 && res[res.length()-1] == s[i]){
                res.pop_back();
            }else{
                res += s[i];
            }
        }
        return res;
    }
};