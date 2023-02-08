class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int count, dist, l = s.length();

        if(minJ >= l || s[l-1] == '1'){
            return false;
        }
        if(maxJ >= l-1){
            return true;
        }
        vector<int>rec(s.length(), 0);

        for(int i=l-2;i>=0;i--){
            if(s[i] == '1' || i + minJ >= l){
                rec[i] = rec[i+1] + 1;
                continue;
            }

            if(i + maxJ >= l-1){
                count = rec[i + minJ];
                dist = l - (i + minJ);
            }else{
                count = rec[i + minJ] - rec[i + maxJ + 1];
                dist = maxJ - minJ + 1;
            }
            if(count == dist){
                s[i] = '1';
                rec[i] = rec[i+1] + 1;
            }else{
                rec[i] = rec[i+1];
            }
        }
        return s[0] == '0';
    }
};