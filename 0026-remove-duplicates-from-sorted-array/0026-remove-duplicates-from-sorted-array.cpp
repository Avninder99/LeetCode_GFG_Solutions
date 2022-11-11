class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int size = n.size(), ptr=0;
        for(int i=1;i<size;i++){
            if(n[ptr] != n[i]){
                n[++ptr] = n[i];
            }
        }
        return ptr+1;
    }
};