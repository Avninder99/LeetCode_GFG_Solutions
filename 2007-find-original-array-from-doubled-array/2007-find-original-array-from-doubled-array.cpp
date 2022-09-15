class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        int size = c.size(), sptr=0;
        sort(c.begin(), c.end());
        vector<int>v1,v2;
        for(int i=1;i<size;i++){
            if(c[i] == 2*c[0]){
                sptr = i;
                c[i] = -1;
                v1.push_back(c[0]);
                c[0] = -1;
            }
        }
        
        if(sptr == 0) return v2;
        for(int i=1;i<size;i++){
            if(c[i] != -1){
                if(sptr <= i) sptr = i+1;
                while(sptr < size && c[sptr] != 2*c[i]){
                    sptr++;
                }
                if(sptr >= size) return v2;
                c[sptr] = -1;
                v1.push_back(c[i]);
                c[i] = -1;
            }
        }
        return v1;
    }
};