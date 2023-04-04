class Solution {
public:
    int partitionString(string s) {
        vector<int>rec(26, 0);
        int count = 1;
        for(int i=0;i<s.length();i++){
            if(rec[(int)s[i] - 97] > 0){
                count++;
                rec = vector<int>(26, 0);
            }
            rec[(int)s[i] - 97] = 1;
        }
        return count;
    }
};