class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int i = 0;i<nums.size(); i++) {
            if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
                *it = nums[i];
            }
        }
        return sub.size();
    }
};

