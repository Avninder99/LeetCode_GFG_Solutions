class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long counter = 0, res = 0;
        nums.push_back(1);
        for(auto itr: nums){
            if(itr == 0){
                counter++;
            }else{
                counter = 0;
            }
            res += counter;
        }
        return res;
    }
};