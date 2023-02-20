class Solution {
public:
    int searchInsert(vector<int>& n, int t) {
        int left=0, right=n.size(), mid;
        if(t < n[0]) return 0;
        else if(t > n[n.size()-1]) return n.size();
        
        while(left <= right){
            mid = (left+right)/2;
            
            if(n[mid] == t) return mid;
            else if(n[mid] > t){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};