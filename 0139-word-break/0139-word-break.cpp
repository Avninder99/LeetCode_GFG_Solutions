class Solution {
public:
    unordered_map<string,int>m1;
    unordered_set<char>s1;
    
    bool func(string &s, int ptr, int len, vector<int>&dp){
        if(ptr == len) return true;
        if(ptr > len || s1.count(s[ptr]) == 0) return false;
        bool check=false;
        if(dp[ptr] == -1){
            for(int i=1;i<21 && !check && ptr+(i-1) < len;i++){
                if(m1.find(s.substr(ptr,i)) != m1.end()){
                    check=func(s, ptr+i, len, dp);
                }
            }
            dp[ptr] = check;
        }
        return dp[ptr];
    }
    
    bool wordBreak(string s, vector<string>& wd) {
        // unordered_map<string,int>m1;
        // unordered_set<char>s1;
        for(int i=0;i<wd.size();i++){
            s1.insert(wd[i][0]);
            m1[wd[i]] = wd[i].length();
        }
        int len = s.length();
        vector<int>dp(len+1, -1);
        return func(s, 0, len, dp);
    }
};