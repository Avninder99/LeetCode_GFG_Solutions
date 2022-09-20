class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>q1;
        int size = s.size(),x,y;
        for(int i=0;i<size;i++){
            q1.push(s[i]);
        }
        while(q1.size() > 1){
            y = q1.top(), q1.pop(), x = q1.top(), q1.pop();
            if(y-x) q1.push(y-x);
        }
        q1.push(0);
        return q1.top();
    }
};