class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        int rs = g[0].size(), cs = g.size(), maxSum=INT_MIN;
        for(int i=1;i<cs-1;i++){
            for(int j=1;j<rs-1;j++){
                // basic approach O(N) time complexity and O(1) space complexity
                // D + B + F + A + C + E + G
                maxSum = max(maxSum, g[i][j]+g[i-1][j]+g[i+1][j]+g[i-1][j-1]+g[i-1][j+1]+g[i+1][j-1]+g[i+1][j+1]);
            }
        }
        return maxSum;
    }
};