class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int size = nums.size(), rtotal=0, ltotal = 0;
        for(int i=0;i<size;i++){
            rtotal += nums[i];
        }
        for(int i=0;i<size;i++){
            if(ltotal == rtotal - nums[i] - ltotal){
                return i;
            }
            ltotal += nums[i];
        }
        return -1;
    }
};