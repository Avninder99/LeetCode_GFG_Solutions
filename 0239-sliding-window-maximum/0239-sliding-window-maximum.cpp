class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }
        
        priority_queue<pair<int, int>>pq;    // val, index (max-heap)
        
        int lptr = 0, rptr = k-1, size = nums.size();
        for(int i=lptr;i<=rptr;i++){
            pq.push(make_pair(nums[i], i));
        }
        vector<int>res(size - k + 1);
        int itr = 0;
        res[itr++] = pq.top().first;
                    
        while(rptr < size-1){
            lptr++;
            rptr++;
            pq.push(make_pair(nums[rptr], rptr));
            while(pq.top().second < lptr){
                pq.pop();
            }
            res[itr++] = pq.top().first;
        }
        return res;
    }
};