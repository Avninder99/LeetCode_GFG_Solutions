class Solution {
public:
    vector<vector<int>>v1;
    
    void func1(vector<int>c, int itr, int c_size, vector<int>temp, int sum, int t_sum){
        // cout << "ran" << endl;
        if(sum == t_sum){       // only for safety (not being used)
            v1.push_back(temp);
            return;
        }
        else if(sum > t_sum || itr >= c_size) return;
        
        // func1(c, itr+1, c_size, temp, sum, t_sum);
        // sum += c[itr];
        // temp.push_back(c[itr]);
        // func1(c, itr+1, c_size, temp, sum, t_sum);
        // temp.pop_back();
        
        int prev = -1;
        for(int i=itr ; i<c_size ; i++){
            // func1(c, itr+1, c_size, temp, sum, t_sum);
            sum += c[i];
            temp.push_back(c[i]);
            if(c[i] != prev) func1(c, i+1, c_size, temp, sum, t_sum);
            sum -= c[i];
            temp.pop_back();
            prev = c[i];
        }
        
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v2;
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        func1(candidates, 0, candidates.size(), v2, sum, target);
        
        return v1;
    }
};