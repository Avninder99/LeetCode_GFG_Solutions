class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>pq;
        for(auto itr: s){
            pq.push(itr);
        }
        while(pq.size() > 1){
            int s1 = pq.top(), s2;
            pq.pop();
            s2 = pq.top();
            pq.pop();
            if(s1 != s2){
                pq.push(s1 - s2);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};