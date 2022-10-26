class Solution {
public:
    vector<vector<int>>v1;
    
    void func1(vector<int>c, int inner_itr, int c_size,  vector<int>temp, int sum, int t_sum){
        if(sum == t_sum){       // only for safety (not being used)
            // v1.push_back(temp);
            return;
        }
        else if(sum > t_sum) return;
        
        for(int i=inner_itr; i<c_size; i++){
            sum += c[i];
            temp.push_back(c[i]);
            if(sum == t_sum){
                v1.push_back(temp);
            }else if(sum < t_sum){
                func1(c, i, c_size, temp, sum, t_sum);
            }
            sum -= c[i];
            temp.pop_back();
              
        }
        return;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v2;
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        func1(candidates, 0, candidates.size(), v2, sum, target);
        
        return v1;
    }
};