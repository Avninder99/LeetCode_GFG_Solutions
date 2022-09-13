class Solution {
public:
    vector<vector<int>>v1;
    // v1[left side][right side] = result
    int func1(int numl, int numr){
        int l=0,r=0,tl,tr;
        if(numl == 1) l = 1;
        else{
            for(int i=0;i<numl;i++){
                if(v1[i][numl-1-i] != -1) tl = v1[i][numl-1-i];
                else{
                    tl = func1(i, numl-1-i);
                    v1[i][numl-1-i] = tl;
                }
                l += tl;
            }
        }
        if(numr == 1) r = 1;
        else{
            for(int i=0;i<numr;i++){
                if(v1[i][numr-1-i] != -1) tr = v1[i][numr-1-i];
                else{
                    tr = func1(i, numr-1-i);
                    v1[i][numr-1-i] = tr;
                }
                r += tr;
            }
        }
        if(l==0){
            if(r==0) return 1;
            else return r;
        }else if(r==0) return l;
        else return l*r;
    }
    int numTrees(int n) {
        if(n==1) return 1;
        vector<vector<int>>v2 (n, vector<int>(n, -1));
        v1 = v2;
        int res=0,t;
        for(int i=0;i<n;i++){
            if(v1[i][n-1-i] != -1) t = v1[i][n-1-i];
            else{
                t = func1(i, n-1-i);
                v1[i][n-1-i] = t;
            }
            res += t;
        }
        return res;
    }
};