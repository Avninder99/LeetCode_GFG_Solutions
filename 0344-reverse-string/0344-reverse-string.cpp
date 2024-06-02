class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size(), holder;
        for(int i=0;i<size/2;i++) {
            holder = s[i];
            s[i] = s[size - 1 - i];
            s[size - 1 - i] = holder;
        }
    }
};