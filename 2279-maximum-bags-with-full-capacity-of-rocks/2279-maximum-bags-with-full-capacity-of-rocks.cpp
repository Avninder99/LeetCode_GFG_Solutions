class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int addR) {
        vector<int>rec(c.size(), 0);
        for(int i=0;i<c.size();i++){
            rec[i] = c[i] - r[i];
        }
        sort(rec.begin(), rec.end());
        int count = 0;
        for(auto itr: rec){
            if(itr <= addR){
                addR -= itr;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};