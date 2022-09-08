class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        vector<vector<int>>v1;
        int size=g.size(),gleft=0,j;
        for(int i=size-1;i>=0;i--){
            gleft = g[i];
            j=i;
            while(gleft >= 0){
                gleft -= c[j];
                if(gleft < 0) break;
                j = (j+1)%size;
                gleft += g[j];
                if(j == i) return i;
            }
        }
        return -1;
    }
};