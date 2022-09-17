class Solution {
public:
    int characterReplacement(string s, int k) {
        // approach largest substring with k different characters
        // use sliding window 26 times (26 english characters)
        int len = s.length(), max_size=0;
        for(int x=65;x<=90;x++){    // 26 iteration
            
            char c = (char)x;
            int lptr=0, rptr=0, size=0, K=k;
            while(rptr < len){
                if(s[rptr] != c){
                    if(K > 0){
                        rptr++;
                        size++;
                        K--;
                    }else{
                        if(s[lptr] != c) K++;
                        lptr++;
                        size--;
                    }
                }else{
                    size++;
                    rptr++;
                }
                max_size = max(size, max_size);
            }
        }
        return max_size;
    }
};