class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size(), curr;
        // for(int i=0;i<size;i++){
        int t=0, i=0;
        while(i < size){
            while(i < size && (nums[i] < 1 || nums[i] == i+1)) i++;
            if(i >= size) break;
            // nums[i] == i+1 element exist (custom condition)
            curr = nums[i];
            nums[i] = -1;
            // t++;
            if(curr <= size){
                if(nums[curr-1] != curr){
                    int temp = nums[curr-1];
                    nums[curr-1] = curr;
                    curr = temp;
                    // t++;
                    while(curr > 0 && curr <= size && nums[curr-1] != curr){
                        temp = nums[curr-1];
                        nums[curr-1] = curr;
                        curr = temp;
                        // t++;
                    }    
                } 
            }
            // i++;
        }
        
        for(int j=0;j<size;j++){
            cout << nums[j] << " ";
            if(nums[j] != j+1) return j+1;   
        }
        return size+1;
    }
};