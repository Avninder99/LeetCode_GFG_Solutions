class Solution {
public:
    int countSubstrings(string s) {
        int count = s.length(), len = s.length(); // counted all single characters
        for(int i=0; i<len; i++){   // counts all odd length palindromic substring
            for(int j=1; j<len; j++){
                if(i-j < 0 || i+j >= len || s[i-j] != s[i+j]) break;
                count++;
            }
        }
        // i, i+1
        for(int i=0;i<len-1;i++){   // counts all even palindromic substrings
            if(s[i] != s[i+1]) continue;
            for(int j=0;j<len;j++){
                if(i-j < 0 || i+1+j >= len || s[i-j] != s[i+1+j]) break;
                count++;
            }
        }
        return count;
    }
};