class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(), t.end());
        int size=t.size(), lptr=-1, rptr=size-1, s=0;
        if(size == 0 || t[0] > p) return 0;
        
        while(lptr < rptr){
            if(t[lptr+1] <= p){
                p -= t[lptr+1];
                s++;
                lptr++;
            }else{
                if(s > 0 && (p+t[rptr] >= t[lptr+1]) ){
                    p = p + t[rptr] - t[lptr+1];
                    rptr--;
                    lptr++;
                }else{
                    break;
                }
            }
        }
        return s;
    }
};