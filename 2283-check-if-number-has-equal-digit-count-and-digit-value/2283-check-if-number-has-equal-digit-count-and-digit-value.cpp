class Solution {
public:
    bool digitCount(string num) {
        vector<int>rec(10, 0);
        for (int i=0; i<num.size(); i++){
            rec[num[i] - '0']++;
        }
        for (int i=0; i<num.size(); i++){
            if (rec[i] != num[i] - '0'){
                return false;   
            }
        }
        return true;
    }
};