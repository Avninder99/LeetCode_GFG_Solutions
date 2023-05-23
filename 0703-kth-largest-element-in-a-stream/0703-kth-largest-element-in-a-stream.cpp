class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>r;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto itr: nums){
            r.push(itr);
        }
        while(r.size() > k){
            r.pop();
        }
    }
    
    int add(int val) {
        if(r.size() < k){
            r.push(val);
        }
        else if(val > r.top()){
            r.push(val);
            r.pop();
        }
        return r.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */