class Solution {
public:
    int search(vector<int>& n, int t) {
        int size=n.size(),l=0,r=n.size()-1,m=(l+r)/2;
        while(l <= r){
            if(n[m] == t) return m;
            else if(n[m] < t){
                l = m+1;
                m = (l+r)/2;
            }else{
                r = m-1;
                m = (l+r)/2;
            }
        }
        return -1;
    }
};