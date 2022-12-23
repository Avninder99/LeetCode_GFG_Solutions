class Solution {
public:
    // Not mine ( exams :| )
    int solveMemo(vector<int>& prices, int day, bool buy, vector<vector<int>> &memo){
        
        if(day >= prices.size()){
            return 0;
        }
        
        int &ans = memo[day][buy];
        
        if(ans != -1){
            return ans;
        }
        
        // First Choice
        int ans1 = solveMemo(prices, day + 1, buy, memo); // no transaction this day
        
        
        // Second Choice
        int ans2 = 0;
        // doing the required transaction this day
        if(buy){
            ans2 = -prices[day] + solveMemo(prices, day + 1, false, memo);
        }else{
            ans2 = prices[day] + solveMemo(prices, day + 2, true, memo);
        }
        
        return ans = max(ans1, ans2);
        
    }
    
    int maxProfit(vector<int>& prices) {
        int ans; 
        // Memoization Solution
        vector<vector<int>> memo(prices.size() + 2, vector<int>(2, -1));
        ans = solveMemo(prices, 0, true, memo);
        return ans;
    }
};