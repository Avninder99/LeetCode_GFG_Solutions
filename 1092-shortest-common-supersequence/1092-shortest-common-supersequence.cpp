class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        // Write your code here.
        int l1 = t1.length(), l2 = t2.length();
        vector<vector<string>>dp(l1 + 1, vector<string>(l2 + 1, "-"));
        string lcs = func(l1, l2, t1, t2, dp) + "+", res = "";
        
        int lptr = 0, ptr1 = 0, ptr2 = 0;
        while(lptr < lcs.length()){
            while(ptr1 < t1.length() && t1[ptr1] != lcs[lptr]){
                res.push_back(t1[ptr1++]);
            }
            ptr1++;
            while(ptr2 < t2.length() && t2[ptr2] != lcs[lptr]){
                res.push_back(t2[ptr2++]);
            }
            ptr2++;
            res.push_back(lcs[lptr++]);
        }
        res.pop_back();
        return res;
    }
    
    string func(int ind1, int ind2, string &t1, string &t2, vector<vector<string>>&dp){
      // base case
        if(ind1 == 0 || ind2 == 0){
            return "";
        }

        if(dp[ind1][ind2] == "-"){
            // choice diagram code
            if(t1[ind1 - 1] == t2[ind2 - 1]){
                dp[ind1][ind2] = func(ind1 - 1, ind2 - 1, t1, t2, dp) + t1[ind1 - 1];
            }else{
                string f, s;
                f = func(ind1 - 1, ind2, t1, t2, dp);
                s = func(ind1, ind2 - 1, t1, t2, dp);
                if(f.length() >= s.length()){
                    dp[ind1][ind2] = f;    
                }else{
                    dp[ind1][ind2] = s;
                }
                
            }
        }
        return dp[ind1][ind2];
    }
};