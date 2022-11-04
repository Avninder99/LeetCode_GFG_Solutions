class Solution {
public:
    string reverseVowels(string s) {
        int len=s.length(), l=0, r=len-1;
        unordered_set<char>s1;
        s1.insert('a');
        s1.insert('e');
        s1.insert('i');
        s1.insert('o');
        s1.insert('u');
        s1.insert('A');
        s1.insert('E');
        s1.insert('I');
        s1.insert('O');
        s1.insert('U');
        char t;
        while(l<r){
            while(l < r && s1.count(s[l]) == 0) l++;
            while(r > l && s1.count(s[r]) == 0) r--;
            if(l < r){
                t = s[l];
                s[l++] = s[r];
                s[r--] = t;
            }
        }
        return s;
    }
};