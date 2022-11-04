class NumArray {
public:
    vector<int>v1;
    NumArray(vector<int>& nums) {
        v1 = nums;
        for(int i=1;i<nums.size();i++) v1[i] += v1[i-1];
    }
    
    int sumRange(int l, int r) {
        return ( v1[r] - ((l == 0) ? 0 : v1[l-1]) );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */