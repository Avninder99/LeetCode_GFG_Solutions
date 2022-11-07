class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int t;
        unordered_map<int,int>m1;
        m1[5] = 0, m1[10] = 0, m1[20] = 0;
        for(int i=0;i<b.size();i++){
            m1[b[i]]++;
            if(b[i] == 5) continue;
            t = b[i] - 5;
            if(t > 5 && m1[10] > 0){
                m1[10] -= 1;
                t -= 10;
            }
            if((t - m1[5]*5) > 0) return false;
            m1[5] -= t/5;
        }
        return true;
    }
};