class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(), p.end());
        int lptr = 0, rptr = p.size() - 1, count = 0;
        while(lptr <= rptr){
            if(lptr == rptr){
                count++, lptr++, rptr--;
            }else if(p[lptr] + p[rptr] <= limit){
                lptr++, rptr--, count++;
            }else{
                rptr--, count++;
            }
        }
        return count;
    }
};