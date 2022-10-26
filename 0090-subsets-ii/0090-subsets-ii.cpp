class Solution {
public:
    vector<vector<int>>v1;
    
    
    void func1(vector<int>&n, int itr, int n_size, bool prev_chosen, int prev_val, vector<int>&v2){
        if(itr == n_size){
            v1.push_back(v2);
            return;
        }
        
        func1(n, itr+1, n_size, false, n[itr], v2);
        if(!(!prev_chosen && prev_val == n[itr])){
            v2.push_back(n[itr]);
            func1(n, itr+1, n_size, true, n[itr], v2);
            v2.pop_back();    
        }
        return;
    }
    
    void func2(vector<int>&n, int itr, int n_size, vector<int>&v2){
        v1.push_back(v2);
        if(itr >= n_size){
            return;
        }
        
        int prev_val=11;
        for(int i=itr;i<n_size;i++){
            if(n[i]==prev_val) continue;
            v2.push_back(n[i]);
            func2(n, i+1, n_size, v2);
            v2.pop_back();
            prev_val=n[i];
        }
    }
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n_size = nums.size();
        vector<int>v2;
        // func1(nums, 0, n_size, false, 11, v2);
        func2(nums, 0, n_size, v2);
        
        return v1;
    }
};