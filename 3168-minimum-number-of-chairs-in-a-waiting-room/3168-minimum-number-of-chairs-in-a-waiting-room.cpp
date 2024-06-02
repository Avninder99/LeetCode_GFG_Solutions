class Solution {
public:
    int minimumChairs(string s) {
        int count = 0, max_count = 0;
        for(auto i: s) {
            if(i == 'E') {
                count++;
            } else {
                count--;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};