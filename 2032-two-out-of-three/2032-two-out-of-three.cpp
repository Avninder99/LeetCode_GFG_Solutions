class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& n1, vector<int>& n2, vector<int>& n3) {
        vector<int>rec (101, 0), res;
        // addition values -> 1, 3, 5
        for(int i=0;i<n1.size();i++) rec[n1[i]] = 1;
        for(int i=0;i<n2.size();i++) rec[n2[i]] < 2 ? rec[n2[i]] += 3 : NULL;
        for(int i=0;i<n3.size();i++) rec[n3[i]] <= 4 ? rec[n3[i]] += 5 : NULL;
        for(int i=1;i<101;i++) if(rec[i] > 5 || rec[i] == 4) res.push_back(i);
        return res;
    }
};