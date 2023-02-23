class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<vector<int>>rec;
        for(int i=0;i<p.size();i++){
            rec.push_back({c[i], p[i]});
        }
        sort(rec.begin(), rec.end());
        priority_queue<int>pq;
        
        int ptr = 0;
        
        if(w < rec[0][0]) return w;
        
        while(k > 0){
            while(ptr < p.size() && rec[ptr][0] <= w){
                pq.push(rec[ptr][1]);
                ptr++;
            }
            if(pq.empty()) break;
            int holder = pq.top();
            pq.pop();
            w += holder;
            k--;
        }
        return w;
    }
};