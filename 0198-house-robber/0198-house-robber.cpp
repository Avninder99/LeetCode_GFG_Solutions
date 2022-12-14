class Solution {
public:
    int rob(vector<int>& n) {
        int size = n.size();
        if(size < 4){
            if(size == 1){
                return n[0];
            }else if(size == 3){
                n[0] += n[2];
            }
        }else{
            n[size-3] += n[size-1];
            for(int i=size-4;i>=0;i--){
                n[i] += max(n[i+2], n[i+3]);
            }
        }
        return max(n[0], n[1]);
    }
};