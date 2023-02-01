class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        string t;
        if(s1.length() < s2.length()){
            t = s1;
            s1 = s2;
            s2 = t;
        }
        
        int l1 = s1.length(), l2 = s2.length();
        
        int ptr1 = 0, ptr2 = 0, tptr;
        while(ptr1 < l1){
            if(s1[ptr1] != s2[ptr2]){
                return "";
            }
            ptr1++;
            ptr2 = (++ptr2) % l2;
        }

        while(l1 != l2){
            if(l1 - l2 < l2){
                t = s2;
                s2 = s1.substr(l2, l1-l2);
                s1 = t;
            }else{
                s1 = s1.substr(l2, l1-l2);
            }
            l1 = s1.length();
            l2 = s2.length();
        }
        return s2;
    }
};