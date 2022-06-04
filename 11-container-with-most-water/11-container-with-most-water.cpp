class Solution {
public:
    int maxArea(vector<int>& h) {
        int size = h.size(), ptr_l = 0, ptr_r = size-1, l, r, curr_amt, max_amt=0, minh;
        
        while(ptr_l < ptr_r){
            minh = h[ptr_l] >= h[ptr_r] ? h[ptr_r] : h[ptr_l];
            curr_amt = minh * (ptr_r - ptr_l);
            
            if(curr_amt > max_amt){
                max_amt = curr_amt;
                l = ptr_l;
                r = ptr_r;
            }else{
                if(h[ptr_l] < h[ptr_r]){
                    ptr_l++;
                }else{
                    ptr_r--;
                }
            }
            
        }
        minh = h[ptr_l] >= h[ptr_r] ? h[ptr_r] : h[ptr_l];
        curr_amt = minh * (ptr_r - ptr_l);

        if(curr_amt > max_amt){
            max_amt = curr_amt;
            l = ptr_l;
            r = ptr_r;
        }
        return max_amt;
    }
};