class Solution {
public:
    vector<int>n;
    Solution(vector<int>& nums) {
        n = nums;
    }
    
    vector<int> reset() {
        return n;
    }
    
    vector<int> shuffle() {
        vector<int> res(n);
        for (int i=0;i < res.size();i++) {
            int pos = rand()%(res.size()-i);
            swap(res[i+pos], res[i]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */