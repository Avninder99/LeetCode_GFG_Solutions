class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        int s = 0, e = size - 1, m = (s + e)/2;
        while(s <= e){
            m = (s + e)/2;
            int ls, rs;
            if(m - 1 >= 0 && nums[m] == nums[m - 1]){
                ls = m - 1 - s;
                rs = e - m;
                if(ls%2){
                    e = m - 2;
                }else{
                    s = m + 1;
                }
            }else if(m + 1 < size && nums[m] == nums[m + 1]){
                ls = m - s;
                rs = e - m + 1;
                if(ls%2){
                    e = m - 1;
                }else{
                    s = m + 2;
                }
            }else{
                return nums[m];
            }
        }
        return nums[m];
    }
};