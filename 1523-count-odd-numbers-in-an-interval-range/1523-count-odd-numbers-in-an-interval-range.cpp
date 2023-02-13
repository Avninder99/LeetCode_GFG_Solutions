class Solution {
public:
    int countOdds(int l, int h) {
        int res = (h-l)/2;
        if(l%2 || h%2){
            res++;
        }
        return res;
    }
};