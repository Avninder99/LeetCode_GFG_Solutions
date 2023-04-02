class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long ss) {
        sort(p.begin(), p.end());
        long long int l = 0, h = p.size() - 1, m = l + (h-l)/2, res = 0, t, holder;
        vector<int>rec;
        
        for(long long int itr: s){
            t = (long long int)ceil((long double)ss/itr);
            // perform binary search on p vector to find lower bound of number that satify product condition
            
            l = 0, h = p.size() - 1, m = l + (h-l)/2, holder = p.size();
            
            while(l <= h){
                m = l + (h - l)/2;
                // holder
                if(p[m] >= t){
                    holder = m;
                    h = m - 1;
                }else{
                    l = m + 1; 
                }
            }
            rec.push_back(p.size() - holder);
        }
        return rec;
    }
};