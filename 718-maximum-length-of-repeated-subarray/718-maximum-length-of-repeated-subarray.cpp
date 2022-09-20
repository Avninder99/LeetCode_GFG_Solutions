class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int s1 = n1.size(), s2 = n2.size(), lptr=-1, rptr=0, mins=s2, max=0;
//         bool secmin = true;
//         // if(s1 < s2){
//         //     secmin = false;
//         //     min = s1;
//         // }
//         unordered_map<int, int>m1, m2;
//         for(int i=0;i<s2;i++){
//             m1[n2[i]] += 1;
//         }
//         m2.insert(m1.begin(), m1.end());
//         deque<int>q1;
//         // for(int i=0;i<s1;i++){
//         while(rptr < s1){
//             if(m1[n1[rptr]] > 0){
//                 q1.push_back(n1[rptr]);
//                 m1[n1[rptr]] -= 1;
//                 rptr++;
//                 if(lptr < 0) lptr = 0;
//             }else if(lptr >= 0 && n1[lptr] == n1[rptr] && m2[lptr] > 0){
//                 q1.pop_front();
//                 q1.push_back(n1[rptr]);
//                 lptr++;
//                 rptr++;
//             }else if(lptr >= 0){
//                 while(n1[lptr] != n1[rptr] && lptr < rptr){
//                     m1[n1[lptr]] += 1;
//                     lptr++;
//                     q1.pop_front();
//                 }
//                 if(lptr==rptr){
//                     rptr++;
//                 }
//             }else{
//                 rptr++;    
//             }
            
//             if(q1.size() > max) max = q1.size();
//         }
//         return max;
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};