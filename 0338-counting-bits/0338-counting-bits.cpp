class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(1, 0);
        if(n == 0){
            return res;
        }
        int mb = log2(n);
        for(int i=1;i<=n;i++){
            int count = 0, t = i;
            for(int j=0;j<=mb;j++){
                if(t & 1){
                    count++;
                }
                t = t >> 1;
            }
            res.push_back(count);
        }
        return res;
    }
};