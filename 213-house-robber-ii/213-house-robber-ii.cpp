class Solution {
public:
    int func(vector<int>&n, vector<int>&dp, int ind, bool lastp){
        if(ind < 0) return 0;
        if(ind == 0){
            if(lastp) return 0;
            return n[0];
        }
        if(dp[ind] != -1) return dp[ind];
        int p, np;
        p = n[ind] + func(n, dp, ind-2, lastp);
        np = func(n, dp, ind-1, lastp);
        return dp[ind] = max(p, np);
    }
    int rob(vector<int>& n) {
        int size = n.size();
        if(size == 1) return n[0];
        if(size == 2) return max(n[0], n[1]);
        vector<int>v1(n);
        for(int i=2;i<size;i++){
            int t,nt;
            t = n[i];
            if(i>2) t += n[i-2];
            nt = n[i-1];
            n[i] = max(t,nt);
        }
        int f = max(n[size-1], n[size-2]);
        n = v1;
        for(int i=1;i<size-1;i++){
            int t,nt;
            t = n[i];
            if(i>1) t += n[i-2];
            nt = n[i-1];
            n[i] = max(t,nt);
        }
        int s = max(n[size-2], n[size-3]);
        return max(f, s);
    }
};