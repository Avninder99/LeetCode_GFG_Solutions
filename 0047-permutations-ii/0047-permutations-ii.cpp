class Solution {
public:
    vector<vector<int>>v1;
    vector<int>v2;
    
    void func1(vector<int>n, int size, int lvl){
        
        if(lvl == size){
            v1.push_back(v2);
            return;
        }
        int temp, prev = 11;
        for(int i=0; i<size; i++){
            if(n[i] != 11 && n[i] != prev){
                temp = n[i];
                v2.push_back(n[i]);
                n[i] = 11;
                func1(n, size, lvl+1);
                n[i] = temp;
                v2.pop_back();
                prev = temp;
            }
        }
        
        
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        func1(nums, nums.size(), 0);
        return v1;
    }
};