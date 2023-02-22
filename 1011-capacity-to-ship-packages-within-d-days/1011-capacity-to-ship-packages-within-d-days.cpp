class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int size = w.size(), maxE = *max_element(w.begin(), w.end());
        if(size <= days) return maxE;
        
        int sum = 0;
        for(auto itr: w){
            sum += itr;
        }
        
        int l = maxE, h = sum, m, rec;
        bool possible;
        
        while(h >= l){
            m = (l + (h - l)/2);
            
            possible = false;
            int tempHolder = 0, d = days;
            for(int i=0;i<size && d > 0;i++){
                if(tempHolder + w[i] <= m){
                    tempHolder += w[i];
                }else{
                    d--;
                    tempHolder = w[i];
                    if(d == 0){
                        break;
                    }
                }
                if(i == size - 1){
                    possible = true;
                    break;
                }
            }
            
            if(possible){
                if(rec == m) break;
                rec = m; 
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return rec;
    }
};