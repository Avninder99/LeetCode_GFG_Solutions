class Solution {
public:
    int fib(int n) {
        int prev = 1, prev2 = 0, curr;
        if(n < 2) return n;
        for(int i=2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};