class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size(), l = 1, h = len - 1, m = l + (h-l)/2, exCount, seCount;
        
        while(h >= l){
            m = l + (h-l)/2;
            exCount = 0, seCount = 0;    // smaller than equal to (se)
            for(auto itr: nums){
                if(itr <= m){
                    if(itr == m) exCount++;
                    seCount++;
                }
            }
            if(exCount > 1){
                return m;
            }
            if(seCount > m){
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return m;
    }
};