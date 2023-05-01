class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(), s.end());
        long double avg = 0;
        for(int i=1;i<s.size()-1;i++){
            avg += s[i];
        }
        avg = avg / (long double)(s.size() - 2);
        return avg;
    }
};