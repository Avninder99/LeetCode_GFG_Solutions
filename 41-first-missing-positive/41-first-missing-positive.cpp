class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size(), curr;
        int i=0, temp;
        while(i < size){
            while(i < size && (nums[i] < 1 || nums[i] == i+1)) i++;
            if(i >= size) break;
            // nums[i] == i+1 element exist (custom condition)
            curr = nums[i];
            nums[i] = -1;
            if(curr <= size){
                if(nums[curr-1] != curr){
                    do{
                        temp = nums[curr-1];
                        nums[curr-1] = curr;
                        curr = temp;    
                    }while(curr > 0 && curr <= size && nums[curr-1] != curr);  
                } 
            }
        }
        
        for(int j=0;j<size;j++){
            if(nums[j] != j+1) return j+1;   
        }
        return size+1;
    }
};