class Solution {
public:
    bool halvesAreAlike(string s) {
        int hi = s.length()/2, c1=0, c2=0;
        unordered_set<char>vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<hi;i++){
            if(vowels.count(s[i])){
                c1++;
            }
            if(vowels.count(s[hi + i])){
                c2++;
            }
        }
        return c1 == c2;
    }
};