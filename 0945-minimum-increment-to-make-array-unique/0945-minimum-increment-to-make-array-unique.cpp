class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int counter = 0, size = nums.size();
        for(int ptr = 1; ptr < size; ptr++) {
            if(nums[ptr] <= nums[ptr - 1]) {
                counter += nums[ptr - 1] - nums[ptr] + 1;
                nums[ptr] = nums[ptr - 1] + 1;
            }
        }
        return counter;
    }
};