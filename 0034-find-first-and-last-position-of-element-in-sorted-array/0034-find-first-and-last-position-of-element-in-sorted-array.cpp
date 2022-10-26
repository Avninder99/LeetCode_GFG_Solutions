class Solution {
public:
    vector<int>n;
    int l=-1, r=-1, t;
    void lsearch(int left, int right){
        int middle = (left+right)/2;
        if(n[middle]==t){
            l=middle;
            if(middle>left){
                if(n[middle-1] == t){
                    lsearch(left,middle-1);
                }
            }
            return;
        };
        if(right >= left){
            if(n[middle]>t){
                lsearch(left,middle-1);
            }else{
                lsearch(middle+1,right);
            }
        }
        return;
    }
    void rsearch(int left, int right){
        int middle = (left+right)/2;
        if(n[middle]==t){
            r=middle;
            if(middle<right){
                if(n[middle+1] == t){
                    rsearch(middle+1,right);    
                }    
            }
            
            return;
        };
        if(right >= left){
            if(n[middle]>t){
                rsearch(left,middle-1);
            }else{
                rsearch(middle+1,right);
            }
        }
        return;
        
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums;
        t = target;
        vector<int>v1;
        int n_size = nums.size();
        if(n_size == 0){
            v1.push_back(-1);
            v1.push_back(-1);
            return v1;
        }
        lsearch(0,n_size-1);
        rsearch(0,n_size-1);
        v1.push_back(l);
        v1.push_back(r);
        return v1;
    }
};