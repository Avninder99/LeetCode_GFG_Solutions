class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int>v1(size, false);
        
        for(int i=size-1;i>=0;i--){
            
            if(nums[i] + i >= size-1){
                v1[i] = true;
            }else{
                int temp = nums[i];
                for(int j=1;j<=temp;j++){
                    if(v1[i+j]){
                        v1[i] = true;
                        break;
                    }
                }
            }
        }
        return v1[0];
    }
};