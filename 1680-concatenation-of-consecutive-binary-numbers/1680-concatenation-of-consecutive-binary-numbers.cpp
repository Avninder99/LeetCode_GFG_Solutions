class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res = 0, M = 1e9 + 7, len;
        for (int i = 1; i <= n; i++) {
            len = log2(i)+1;
            res = ((res << len) % M + i) % M;
        }
        return res;
    }
};