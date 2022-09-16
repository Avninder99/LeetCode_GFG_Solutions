class Solution {
public:
    // int res = INT_MIN;
    vector<vector<int>>dp;
    int func(vector<int>& n, vector<int>& m, int msize, int nsize, int lptr, int rptr, int ptr){
        // if(ptr == msize){
        //     if(csum > res) res = csum;
        //     return;
        // }
        int tl = n[lptr]*m[ptr];
        int tr = n[rptr]*m[ptr];
        if(ptr < msize-1){
            int l,r;
            if(dp[lptr+1][ptr+1] != -10000001){
                l = dp[lptr+1][ptr+1];
            }else{
                l = func(n, m, msize, nsize, lptr+1, rptr, ptr+1);
                dp[lptr+1][ptr+1] = l;    
            }
            
            if(dp[lptr][ptr+1] != -10000001){
                r = dp[lptr][ptr+1];
            }else{
                r = func(n, m, msize, nsize, lptr, rptr-1, ptr+1);
                dp[lptr][ptr+1] = r;    
            }
            return max(tl + l, tr + r);
        }
        return max(tl, tr);
    }
    int maximumScore(vector<int>& n, vector<int>& m) {
        int msize = m.size(), nsize = n.size(), lptr = 0, rptr = nsize-1;
        vector<vector<int>>v1 (msize, vector<int>(msize, -10000001));
        dp = v1;
        v1.clear();
        return func(n, m, msize, nsize, 0, nsize-1, 0);
        // return res;
    }
};