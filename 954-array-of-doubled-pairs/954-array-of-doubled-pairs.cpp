class Solution {
public:
    bool canReorderDoubled(vector<int>& c) {
        int size = c.size(), sptr=0;
        // for(int i=0;i<size;i++){
        //     c[i] = abs(c[i]);
        // }
        sort(c.begin(), c.end());
        for(int i=1;i<size;i++){
            if(c[i] == 2*c[0] || c[i] == (0.5)*c[0]){
                sptr = i;
                c[i] = -10000000;
                c[0] = -10000000;
            }
        }
        if(sptr == 0) return false;
        for(int i=1;i<size;i++){
            if(c[i] != -10000000){
                if(sptr <= i) sptr = i+1;
                while(sptr < size && (c[sptr] != 2*c[i] && c[sptr] != (0.5)*c[i])){
                    sptr++;
                }
                if(sptr >= size) return false;
                c[sptr] = -10000000;
                c[i] = -10000000;
            }
        }
        return true;
    }
};