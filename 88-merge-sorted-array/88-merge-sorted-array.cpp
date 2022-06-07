class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        long int size_nums1 = m+n-1, temp_m=m-1, temp_n=n-1;
        bool check1 = true, check2 = true;
        if(temp_m < 0)
            check1 = false;
        if(temp_n < 0)
            check2 = false;
        for(int i=size_nums1; i>=0 ;i--){
            if(check1 && check2){
                if(nums1[temp_m] > nums2[temp_n]){
                    nums1[i] = nums1[temp_m];
                    temp_m--;
                    if(temp_m < 0)
                        check1 = false;
                }else{
                    nums1[i] = nums2[temp_n];
                    temp_n--;
                    if(temp_n < 0)
                        check2 = false;
                }
            }else if(check1){
                nums1[i] = nums1[temp_m];
                temp_m--;
                if(temp_m < 0)
                    check1 = false;
            }else{
                nums1[i] = nums2[temp_n];
                    temp_n--;
                    if(temp_n < 0)
                        check2 = false;
            }
        }
    }
};