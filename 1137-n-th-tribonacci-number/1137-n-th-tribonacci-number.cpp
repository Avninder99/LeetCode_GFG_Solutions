class Solution {
public:
    int tribonacci(int n) {
        if(n < 3) return (bool)n;
        int a = 0, b = 1, c = 1, t;
        for(int i=3;i<n+1;i++){
            t = c;
            c = c + b + a;
            a = b;
            b = t;
        }
        return c;
    }
};