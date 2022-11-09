class StockSpanner {
public:
    vector<vector<int>>rec;
    // here vector "rec" is a 2d vector of size N x 2 where 
    // vector<int>rec;
    // int prevE=10000000;
    StockSpanner() {}
    
    int next(int p) {
        int ans=1;
        if(rec.size() > 0){
            int itr = rec.size()-1;
            while(itr >= 0 && rec[itr][0] <= p){
                ans += rec[itr][1];
                if(itr - rec[itr][1] >= 0 && rec[ itr - rec[itr][1] ][0] <= p){
                    itr -= rec[itr][1];
                }else break;
            }
            rec.push_back({p, ans});
        }else{
            ans = 1;
            rec.push_back({p, 1});
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */