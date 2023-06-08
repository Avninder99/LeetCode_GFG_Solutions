class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        // Follow up solution
        // Time Complexity -> O(N + M)
        int cs = g.size(), rs = g[0].size(), c = 0, r = rs - 1, count = 0;
        while(c < cs && r >= 0){
            if(g[c][r] < 0){
                count += (cs - c);
                r--;
            }else{
                c++;
            }
        }
        return count;
    }
};