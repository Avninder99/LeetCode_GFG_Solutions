class Solution {
public:
    int strStr(string h, string n) {
        int len1 = h.length(), len2 = n.length(), nxt;
        bool found, check1;
        for(int i=0;i<len1;i++){
            if(h[i] == n[0] && len1 - i >= len2){
                found = true;
                check1 = true;
                for(int j=1;j<len2;j++){
                    if(check1 && h[i+j] == n[0]){
                        nxt = i+j;
                        check1 = false;
                    }
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