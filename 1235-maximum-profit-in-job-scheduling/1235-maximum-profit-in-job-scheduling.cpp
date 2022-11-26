// bool scol(const vector<int>&a, const vector<int>&b){
//     return a[0] < b[0];
// }
class Solution {
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
    
    
    // DP but still TLE ...
// public:
//     int func(vector<vector<int>>&jobs, int itr, int size, vector<int>&dp){
//         if(itr >= 0 && dp[itr] != 0){
//             return dp[itr];
//         }
//         int maxi = jobs[itr][2];
//         for(int i=itr+1; i<size; i++){
//             if(jobs[i][0] >= jobs[itr][1]){
//                 maxi = max(maxi, func(jobs, i, size, dp) + jobs[itr][2] );
//             }
//         }
//         dp[itr] = maxi;
//         return maxi;
//     }
//     int jobScheduling(vector<int>& sT, vector<int>& eT, vector<int>& p) {
//         vector<vector<int>>jobs;
//         int size = sT.size();
//         vector<int>dp(size, 0);
//         for(int i=0; i<size; i++){
//             jobs.push_back({eT[i], sT[i], p[i]});
//         }
//         sort(jobs.begin(), jobs.end(), scol);
//         dp[size - 1] = jobs[size - 1][2];
//         int m = 0;
//         for(int i=0;i<size;i++){
//             m = max(m, func(jobs, -1, size, dp));
//         }
//         return m;
//     }
};