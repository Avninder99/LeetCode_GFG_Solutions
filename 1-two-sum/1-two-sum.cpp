class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arr1[2],n1,n2;
        vector<int>v1,v2 = nums;
        sort(nums.begin(), nums.end());
        int length = nums.size(), length1 = length, b1 = 0, e1 = length-1;
        while(length--){
            if(nums[b1]+nums[e1] > target){
                e1--;
            }else if(nums[b1]+nums[e1] < target){
                b1++;
            }else{
                break;
            }
        }
        for(int i = 0;i<length1;i++){
            if(v2[i] == nums[b1]){
                v1.push_back(i);
            }else if(v2[i] == nums[e1]){
                v1.push_back(i);
            }
        }
        return v1;
    }
    
};