class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int size = nums.size(), zcount = 0, res = 0;
        vector<int> lcount(size, 0), rcount(size, 0);
        
        for(int i=0;i<size;i++) {
            lcount[i] = zcount;
            if(nums[i] == 0) {
                zcount++;
            } else {
                zcount = 0;
            }
        }
        
        zcount = 0;
        for(int i=size-1;i>=0;i--) {
            rcount[i] = zcount;
            if(nums[i] == 0) {
                zcount++;
            } else {
                zcount = 0;
            }
        }
        
        // handles goal == 0 cases
        if(goal == 0) {
            for(int i=0;i<size;i++) {
                if(nums[i] == 0) {
                    res += (rcount[i] + 1);
                }
            }
            return res;
        }
        
        int lptr=0, rptr=0, sum=0;
        
        for(int i=0;i<size;i++) {
            if(nums[i] == 1) {
                lptr = i;
                rptr = i;
                break;
            }
        }
        if(!nums[lptr]) {
            return 0;
        }
        
        while(rptr < size) {
            sum += nums[rptr];
            
            if(sum == goal) {
                res += ((lcount[lptr] + 1) * (rcount[rptr] + 1));
                
                rptr++;
                while(rptr < size && nums[rptr] != 1) {
                    rptr++;
                }
                
                sum -= nums[lptr++];
                while(lptr < rptr && nums[lptr] != 1) {
                    lptr++;   
                }
            } else if(sum > goal && lptr < rptr) {
                sum -= nums[lptr++];
                while(lptr < rptr && nums[lptr] != 1) {
                    lptr++;   
                }
            } else {
                rptr++;
                while(rptr < size && nums[rptr] != 1) {
                    rptr++;
                }
            }
        }
        return res;
    }
};