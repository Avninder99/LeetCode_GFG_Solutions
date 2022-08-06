class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        vector<int>v1(size, 50001);
        
        for(int i=size-1;i>=0;i--){
            if(nums[i] + i >= size-1){
                v1[i] = 1;
            }else{
                int min=50000;
                for(int j=1;j<=nums[i];j++){
                      if(v1[i+j] < min){
                          min = v1[i+j];
                      }
                }
                if(min < 50000){
                    v1[i] = min + 1;
                }
            }
        }
        return v1[0];
    }
};