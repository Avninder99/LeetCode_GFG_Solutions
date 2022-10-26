class Solution {
public:
    // bool checkSubarraySum(vector<int>& n, int k) {
    //     int lptr=0, rptr=1, size=n.size(), temp;
    //     unordered_map<int,int>m1;
    //     if(size == 1) return false;
    //     m1[n[0]] = 0;
    //     m1[0] = -1;
    //     for(int i=1;i<size;i++){
    //         n[i] += n[i-1];
    //         if(m1.find(n[i]) == m1.end()) m1[n[i]] = i;
    //     }
    //     for(int i=1;i<size;i++){
    //         if((m1.find(n[i]%k) != m1.end() && m1[n[i]%k] < i-1) || 
    //            (m1.find(n[i]) != m1.end() && m1[n[i]] < i-1)) return true;
    //     }
    //     return false;
    // }
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)
            return false;

        unordered_map<int, int> mp;

        mp[0]=-1;
        
        int runningSum=0;
        
        for(int i=0;i<nums.size();i++){
            runningSum+=nums[i];
            
            if(k!=0) 
                runningSum = runningSum%k;
            
            if(mp.find(runningSum)!=mp.end()){
                if(i-mp[runningSum]>1)
                    return true;
            }
            else{   
                mp[runningSum]=i;
            }
                    
        }
        
        return false;
        
    }
};