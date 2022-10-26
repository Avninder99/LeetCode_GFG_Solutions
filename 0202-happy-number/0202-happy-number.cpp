class Solution {
public:
    bool isHappy(int n) {
        vector<int>sq(10,-1);
        for(int i=0;i<10;i++) sq[i] = i*i;
        unordered_set<int>s1;
        s1.insert(n);
        unsigned long long int sum, t;
        while(n != 1){
            sum = 0;
            while(n != 0){
                t = n%10;
                n /= 10;
                sum += sq[t];
            }
            if(s1.count(sum) == 1) return false;
            s1.insert(sum);
            n = sum;
        }
        return true;
    }
};