class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int size = n.size(), ptr=1;
        if(size == 1) return 1;
        for(int i=2;i<size;i++){
            if(n[ptr] != n[i] || n[ptr-1] != n[i]){
                n[++ptr] = n[i];
            }
        }
        return ptr+1;
    }
    
};