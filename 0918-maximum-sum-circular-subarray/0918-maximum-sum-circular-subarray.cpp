class Solution {
public:
    int maxSubarraySumCircular(vector<int>& n) {
        long long int tsum = 0, msum = INT_MIN, r = 0, maxi = INT_MIN, mini = INT_MAX, total = 0;
        
        // find max subarray and max element
        while(r < n.size()){
            total += n[r];
            if(n[r] >= 0 || tsum + n[r] >= 0){
                tsum += n[r];
                msum = max(msum, tsum);
            }else{
                tsum = 0;
            }
            if(n[r] > maxi){
                maxi = n[r];
            }
            r++;
        }
        maxi = max(msum, maxi);
        
        r = 0;
        msum = INT_MAX;
        while(r < n.size()){
            if(n[r] <= 0 || tsum + n[r] <= 0){
                tsum += n[r];
                msum = min(msum, tsum);
            }else{
                tsum = 0;
            }
            if(n[r] < mini){
                mini = n[r];
            }
            r++;
        }
        mini = min(msum, mini);
        if(mini == total) return maxi;
        return max(maxi, total - mini);
    }
};