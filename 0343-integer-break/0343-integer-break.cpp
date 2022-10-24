class Solution {
public:
    int integerBreak(int n) {
        int prod=1, sum=0;
        if(n<4) return n-1;
        while(n){
            if(n>=3){
                n -= 3;
                prod *= 3;
            }else if(n == 2){
                prod *= 2;
                n -= 2;
            }else if(n == 1){
                prod = (prod/3)*4;
                n--;
            }
        }
        return prod;
    }
};