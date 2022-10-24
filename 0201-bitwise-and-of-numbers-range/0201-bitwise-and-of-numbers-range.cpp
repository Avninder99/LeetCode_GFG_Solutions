class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int lc=0, rc=0, tl=l, tr=r, ll, rl, md=0;
        while(tl){
            lc++;
            tl = tl>>1;
        }
        while(tr){
            rc++;
            tr = tr>>1;
        }
        if(lc != rc) return 0;
        tl=l, tr=r;
        for(int i=1;i<lc;i++){
            ll = tl&1, rl = tr&1;
            tl = tl>>1, tr = tr>>1;
            if(ll != rl) md = i;
        }
        l = l>>md;
        l = l<<md;
        return l;
    }
};