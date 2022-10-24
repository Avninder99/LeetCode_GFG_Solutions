class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        for(int i=d.size()-1;i>=0;i--){
            d[i] = (d[i]+1)%10;
            if(d[i] != 0) break;
        }
        if(d[0] != 0) return d;
        d.push_back(0);
        for(int i=d.size()-1;i>0;i--) d[i] = d[i-1];
        d[0] = 1;
        return d;
    }
};