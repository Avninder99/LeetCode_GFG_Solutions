// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        long long int l=0,r=n;
        int m = (l+r)/2;
        while(l <= r){
            if(isBadVersion(m)){
                if(isBadVersion(m-1)){
                    r = m-1;
                    m = (l+r)/2;
                }else{
                    return m;
                }
            }else{
                l = m+1;
                m = (l+r)/2;
            }
        }
        return -1;
    }
};