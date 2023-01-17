class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int hold1Count = 0, flipCount = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                flipCount++;
                flipCount = min(hold1Count, flipCount);
            }else{
                hold1Count++;
            }
        }
        return flipCount;
    }
};