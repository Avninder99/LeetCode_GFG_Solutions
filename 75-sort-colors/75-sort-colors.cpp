class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size(), rptr=0, ptr=0, bptr=size-1, temp;
        int i=0;
        while(i<size && nums[i] == 0){
            rptr++;
            i++;
        }
        i=size-1;
        
        while(i>=0 && nums[i] == 2){
            bptr--;
            i--;
        }
        
        i=rptr;
        while(i<=bptr && rptr <= bptr){
            if(nums[i] == 0){
                nums[i] = nums[rptr];
                nums[rptr] = 0;
                rptr++;
                i++;
            }else if(nums[i] == 2){
                nums[i] = nums[bptr];
                nums[bptr] = 2;
                bptr--;
            }else{
                i++;
            }
        }
    }
};