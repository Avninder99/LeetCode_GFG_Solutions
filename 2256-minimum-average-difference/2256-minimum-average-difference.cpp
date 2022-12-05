class Solution {
public:
    int minimumAverageDifference(vector<int>& n) {
        int size = n.size();
        if(size==1) return 0;
        vector<long long int>nums(size, 0);
        nums[0] = n[0];
        for(int i=1;i<size;i++){
            nums[i] = n[i] + nums[i-1];
        }
        int minad=INT_MAX, res=0;
        for(int i=0;i<size-1;i++){
            int ad = abs( ( ( nums[size-1] - nums[i] )/(size-i-1) ) - ( nums[i]/(i+1) ) );
            if(ad < minad){
                minad = ad;
                res = i;
            }
        }
        if( nums[size-1]/size < minad ){
            res = size-1;
        }
        return res;
    }
};