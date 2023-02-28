class Solution {
public:
    int minOperations(int n) {
        int mid, avg;
        if(n%2){
            mid = n/2;
            avg = (2*mid) + 1;
        }else{
            mid = n/2 - 1;
            avg = ((2*mid) + 1 + (2*(mid + 1)) + 1) / 2;
        }
        int sum = 0;
        for(int i=0; i<=mid; i++){
            int val = 2*i + 1;
            sum += abs(avg - val);
        }
        return sum;
    }
};