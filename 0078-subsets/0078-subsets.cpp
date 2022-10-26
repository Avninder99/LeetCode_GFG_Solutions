class Solution {
public:
    vector<vector<int>>v1;
    vector<int>v2;
    
    void func1(vector<int>&n, int itr, int n_size, vector<int>&arr){
        if(itr == n_size){
            v1.push_back(arr);
            return;
        }
        func1(n, itr+1, n_size, arr);
        arr.push_back(n[itr]);
        func1(n, itr+1, n_size, arr);
        arr.pop_back();
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        func1(nums, 0, nums.size(), v2);
        return v1;
    }
};