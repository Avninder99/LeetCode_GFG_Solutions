class Solution {
public:
    int strStr(string h, string n) {
        int len2 = n.length(), len1 = h.length() - len2;
        bool found;
        for(int i=0;i<=len1;i++){
            if(h[i] == n[0]){
                found = true;
                for(int j=1;j<len2;j++){
                    if(h[i+j] != n[j]){
                        found = false;
                        break;
                    }
                }
                if(found) return i;
            }
        }
        return -1;
    }
};