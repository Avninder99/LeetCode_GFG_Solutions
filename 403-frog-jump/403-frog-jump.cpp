class Solution {
public:
    bool func(vector<int>&s, int curr, int lastj, int size, unordered_map<int,int>&m1, vector<vector<int>>&dp){
        
        if(curr == s[size-1]) return true;
        auto ptr = m1.find(curr);
        int itr=-1;
        if(ptr == m1.end()) return false;
        else{
            itr = ptr->second;
        }
        bool found = false;
        if(lastj-1 > 0){
            if(dp[itr][lastj-1] != -1) found = (bool)dp[itr][lastj-1];
            else{
                found = func(s, curr+lastj-1, lastj-1, size, m1, dp);
                dp[itr][lastj-1] = (bool)found;
            }
        }
            
        if(lastj > 0 && !found){
            if(dp[itr][lastj] != -1) found = (bool)dp[itr][lastj];
            else{
                found = func(s, curr+lastj, lastj, size, m1, dp);
                dp[itr][lastj] = (bool)found;                
            }
        }
            
        if(!found){
            if(dp[itr][lastj+1] != -1) found = (bool)dp[itr][lastj+1];
            else{
                found = func(s, curr+lastj+1, lastj+1, size, m1, dp);
                dp[itr][lastj+1] = (bool)found;    
            }
        }
            
        return found;
    }
    bool canCross(vector<int>& s) {
        int size = s.size();
        unordered_map<int, int> m1;     // value, index
        vector<vector<int>>dp (size, vector<int> (size, -1));
        for(int i=0;i<size;i++){
            m1.insert({s[i], i});
        }
        if(size <= 1) return true;
        if(s[1] > s[0]+1) return false;
        return func(s, s[1], 1, size, m1, dp);
    }
};