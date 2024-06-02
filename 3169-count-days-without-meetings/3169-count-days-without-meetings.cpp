class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        int count = 0, l = 0;
        sort(m.begin(), m.end());
        if(m[0][0] > 1) {
            count += m[0][0] - 1;
        }
        l = m[0][1];
        for(int i=1;i<m.size();i++) {
            if(m[i][0] > l + 1) {
                count += m[i][0] - l - 1;
                l = m[i][1];
            } else {
                l = max(l, m[i][1]);
            }
        }
        count += d - l;
        return count;
    }
};