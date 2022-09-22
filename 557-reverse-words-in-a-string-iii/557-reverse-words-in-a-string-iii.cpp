class Solution {
public:
    string reverseWords(string s) {
        s += ' ';
        int size = s.length(), lptr=0, rptr=0, count, t;
        while(rptr < size){
            if(s[rptr] != ' '){
                rptr++;
            }else{
                count = (rptr-lptr)/2;
                for(int i=0;i<count;i++){
                    t = s[lptr+i];
                    s[lptr+i] = s[rptr-1-i];
                    s[rptr-1-i] = t;
                }
                lptr = ++rptr;
            }
        }
        s.pop_back();
        return s;
    }
};