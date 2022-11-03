class Solution {
public:
    void func(int ind, unordered_set<int>&s1, vector<vector<int>>&c, int &size){
        if(s1.count(ind) == 0) return;
        s1.erase(ind);
        for(int i=0;i<size;i++) if(c[ind][i] == 1) func(i, s1, c, size);
        return;
    }
    int findCircleNum(vector<vector<int>>& c) {
        int size=c.size(), counter=0;
        unordered_set<int>s1;
        for(int i=0;i<size;i++) s1.insert(i);
        for(int i=0;i<size;i++){
            if(s1.count(i) == 1){
                counter++;
                func(i, s1, c, size);
            }
        }
        return counter;
    }
};