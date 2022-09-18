class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        long long var_l=INT_MIN, var_r=INT_MIN;
        unsigned long long int left_max[n], right_max[n], min_h, water_amt=0;
        
        for(int i=0;i<n;i++){
            if(height[i]>=var_l){
                var_l = height[i];
            }
            left_max[i] = var_l;
            
            if(height[n-1-i]>=var_r){
                var_r = height[n-1-i];
            }
            right_max[n-1-i] = var_r;
        }
        for(int i=0;i<n;i++){
            min_h = min(left_max[i], right_max[i]);
            if(height[i]<min_h){
                water_amt += min_h-height[i];
            }
        }
        return water_amt;
    }
};