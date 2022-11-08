class Solution {
public:
    string makeGood(string s) {
        string s1 = "";
        s1 += s[0];
        for(int i=1;i<s.length();i++){
            while(s1.length() && 
                  i < s.length() && 
                  abs(s1[s1.length()-1] - s[i]) == 32){
                s1.pop_back();
                i++;
            }
            if(i<s.length()) s1 += s[i];
        }
        return s1;
    }
};