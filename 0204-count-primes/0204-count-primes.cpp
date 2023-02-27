class Solution {
public:
    int countPrimes(int n) {
        vector<bool>rec(n, true);
        for(int i=2;i*i<n;i++){
            if(rec[i]){
                for(int j=i*i; j<n; j+=i){
                    rec[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++){
            if(rec[i]) count++;
        }
        return count;
    }
};