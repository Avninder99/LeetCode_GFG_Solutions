class Solution {
public:
    int numSubseq(vector<int>& nums, int t) {
        
        vector<int>rec(nums.size() + 1, 1);
        long long int temp = 1;
        for(int i=1;i<=nums.size();i++){
            temp = (temp*2)%1000000007;
            rec[i] = temp;
        }
        sort(nums.begin(), nums.end());
        
        long long int l = 0, r = nums.size() - 1, res = 0;
        
        while(l <= r && nums[l] * 2 <= t){
            while(nums[l] + nums[r] > t){
                r--;
            }
            res = (res + rec[r - l])%1000000007;
            l++;
        }
        return res;
    }
};