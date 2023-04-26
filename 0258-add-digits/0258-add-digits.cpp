class Solution {
public:
    int addDigits(int num) {
        int t1, t2, rec;
        while(num/10 > 0){
            while(num != 0){
                t1 = num%10;
                num /= 10;
                t2 = num%10;
                num /= 10;
                rec += t1 + t2;
            }    
            num = rec;
            rec = 0;
        }
        return num;
    }
};