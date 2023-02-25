class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sptr = nums[0], fptr = nums[nums[0]];
        while(sptr != fptr){
            sptr = nums[sptr];
            fptr = nums[nums[fptr]];
        }
        sptr = nums[0];
        fptr = nums[fptr];
        while(sptr != fptr){
            sptr = nums[sptr];
            fptr = nums[fptr];
        }
        return sptr;
    }
};