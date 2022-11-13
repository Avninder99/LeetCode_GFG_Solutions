class Solution {
public:
    string reverseWords(string s) {
        int l1 = s.length();
        // reverse the string
        reverse(s.begin(), s.end());

        // reverse back each word
        reverseWords(s, l1);

        // space handling
        return handleSpaces(s, l1);
    }
  
    void reverseWords(string &s, int &l1) {
        int sptr = 0, eptr = 0;

        while(eptr < l1){
            while(eptr < l1 && s[eptr] != ' ') eptr++;
            reverse(s.begin() + sptr, s.begin() + eptr);
            eptr++, sptr = eptr;
        }
    }
    
    string handleSpaces(string s, int l1) {
        int i = 0, j = 0;
      
        while (j < l1) {
            while (j < l1 && s[j] == ' ') j++;
            while (j < l1 && s[j] != ' ') s[i++] = s[j++];
            while (j < l1 && s[j] == ' ') j++;
            if (j < l1) s[i++] = ' ';
        }
        return s.substr(0, i);
    }
};