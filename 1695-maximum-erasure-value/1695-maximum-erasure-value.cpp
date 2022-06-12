class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int size=nums.size(), res=0, prev=0, dup_ptr=-1, sum=0;
        
        unordered_map<int,int>m1;
        
        for(int i=0;i<size;i++){
            auto itr = m1.find(nums[i]);
            if(itr != m1.end()){
                if(sum > res) res = sum;
                dup_ptr = itr->second;
                for(int i=prev;i<=dup_ptr;i++){
                    sum -= nums[i];
                    m1.erase(nums[i]);
                }
                prev = dup_ptr+1;
            }
            m1[nums[i]] = i;
            sum += nums[i];
        }
        if(sum > res) res = sum;
        return res;
    }
};