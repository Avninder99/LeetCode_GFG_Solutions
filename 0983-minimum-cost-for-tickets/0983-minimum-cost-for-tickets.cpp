class Solution {
public:
    // int arr[3] = {1,7,30};
    int func(vector<int>&d, vector<int>&c, int ptr, int &size, vector<int>&dp){
        if(ptr == size-1) return 0;
        
        if(dp[ptr] == -1){
            int t1=5000000, t2=5000000, t3=5000000;
            t1 = func(d, c, ptr+1, size, dp) + c[0]; // 1 day
            
            int i=0;
            while(d[ptr+i] <= d[ptr]+6) i++;
            t2 = func(d, c, ptr+i, size, dp) + c[1]; // 7 days
            
            int j=0;
            while(d[ptr+j] <= d[ptr]+29) j++;
            t3 = func(d, c, ptr+j, size, dp) + c[2]; // 30 days
            
            dp[ptr] = min(t1, min(t2, t3));  
        }
        return dp[ptr];
    }
    int mincostTickets(vector<int>& d, vector<int>& c) {
        d.push_back(1000);
        int size = d.size();
        vector<int>dp(size+1, -1);
        return func(d, c, 0, size, dp);
    }
};