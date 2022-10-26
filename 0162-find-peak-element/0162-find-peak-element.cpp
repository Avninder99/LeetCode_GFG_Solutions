class Solution {
public:
    int findPeakElement(vector<int>& n) {
        long long int size=n.size(),lptr=0, rptr=size-1, center;
        while(rptr-lptr>1){
            center=(rptr+lptr)/2;
            if(n[center] > n[center-1] && n[center] > n[center+1]) return center;
            else if(n[center-1]>=n[center+1]) rptr=center;
            else lptr=center;
        }
        if(n[lptr] > n[rptr]) return lptr;  // just to be on safe side
        return rptr;
    }
};