class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char>s1;
        int len = s.length(), counter = 0;
        for(int i=0;i<len;i++){
            if(s1.count(s[i])){
                s1.erase(s[i]);
                counter+=2;
            }else{
                s1.insert(s[i]);
            }
        }
        if(s1.size() > 0) return counter+1;
        else return counter;
    }
};