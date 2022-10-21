class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        sort(d.begin(), d.end());
        int size = d.size(), ptr=0,sptr=0;
        vector<int>v1(size, 0);
        bool place = true;
        while(ptr < size){
            sptr %= size;
            if(v1[sptr] == 0){
                if(place){
                    v1[sptr] = d[ptr++];    
                }
                place = !place;
            }
            sptr++;
        }
        return v1;
    }
};