class Solution {
public:
    int maximum69Number (int num) {
        int t=num, divider=1000, addVal=0;
        while(divider){
            if(t/divider == 6){
                addVal = divider * 3;
                break;
            }
            t %= divider;
            divider /= 10;
        }
        return num + addVal;
    }
};