class Solution {
public:
    int maxProfit(vector<int>& p) {
        int buyP = p[0], sellP = p[0], size = p.size(), profit = 0;
        for(int i=0;i<size;i++){
            if(p[i] < sellP){
                profit += (sellP - buyP);
                buyP = p[i];
                sellP = p[i];
            }else if(p[i] > buyP){
                sellP = p[i];
            }
        }
        if(buyP != sellP){
            profit += (sellP-buyP);
        }
        return profit;
    }
};