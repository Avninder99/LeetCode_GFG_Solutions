class Solution {
public:
    int removeElement(vector<int>& n, int val) {
        int size = n.size(), ptr=0;
        for(int i=0;i<size;i++){
            if(n[i] != val){
                n[ptr++] = n[i];
            }
        }
        return ptr;
    }
};