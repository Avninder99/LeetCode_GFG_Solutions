class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int sptr1=0, sptr2=0, ptr1=0, ptr2=0, l1=w1.size(), l2=w2.size();
        while(ptr1 < w1.size() && ptr2 < w2.size()){
            if(w1[ptr1][sptr1++] != w2[ptr2][sptr2++]) return false;
            if(sptr1 == w1[ptr1].length()){
                sptr1=0, ptr1++;
            }
            if(sptr2 == w2[ptr2].length()){
                sptr2=0, ptr2++;
            }
        }
        if(ptr1 == w1.size() && ptr2 == w2.size()) return true;
        return false;
    }
};