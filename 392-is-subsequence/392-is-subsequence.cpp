class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len = t.length(), len2 = s.length(), ptr = 0;
        for(int i=0;i<len;i++){
            if(s[ptr] == t[i]) ptr++;
        }
        if(ptr == len2) return true;
        return false;
    }
};