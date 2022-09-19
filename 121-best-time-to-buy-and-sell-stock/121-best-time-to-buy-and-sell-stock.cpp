class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p_size = prices.size(), max_profit=0, sell_val = prices[p_size-1], buy_val = prices[p_size-1];
        for(int i=p_size-1;i>=0;i--){
            if(prices[i] > sell_val){
                sell_val = prices[i];
                buy_val = prices[i];
            }else if(prices[i] < buy_val){
                buy_val = prices[i];
            }
            if(sell_val - buy_val > max_profit){
                max_profit = sell_val - buy_val;
            }
        }
        return max_profit;
    }
};