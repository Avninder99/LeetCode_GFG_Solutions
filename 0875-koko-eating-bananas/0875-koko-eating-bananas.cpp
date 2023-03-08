class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        sort(piles.begin(), piles.end());
        int l = 1, h = piles[piles.size() - 1] + 1, m, minRate = h, hCount = 0;
        bool verified = false;
        
        while(l <= h){
            m = l + (h - l)/2;
            
            verified = false;
            hCount = 0;
            for(int i=piles.size()-1;i>=0;i--){
                if(hCount > hours){
                    hCount = INT_MAX;
                    break;
                }
                hCount += ceil((double)piles[i]/(double)m);
            }
            verified = (hCount <= hours);
            
            if(verified){
                minRate = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return minRate;
    }
};