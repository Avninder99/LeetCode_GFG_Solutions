class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(auto itr: costs){
            if(itr <= coins){
                coins -= itr;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};