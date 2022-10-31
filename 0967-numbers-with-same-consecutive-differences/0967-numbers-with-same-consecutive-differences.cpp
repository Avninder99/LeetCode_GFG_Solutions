class Solution {
public:
    void func(int n, int &k, unordered_set<int>&s1, int num){
        if(n == 0){
            s1.insert(num);
            return;
        }
        int opd = num%10;
        if(opd - k >= 0) func(n-1, k, s1, num*10 + opd-k);
        if(opd + k <= 9) func(n-1, k, s1, num*10 + opd+k);
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>v1;
        unordered_set<int>s1;
        for(int i=1;i<10;i++) func(n-1, k, s1, i);
        for(auto itr: s1) v1.push_back(itr);
        sort(v1.begin(), v1.end());
        return v1;
    }
};