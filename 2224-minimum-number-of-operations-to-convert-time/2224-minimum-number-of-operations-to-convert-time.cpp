class Solution {
public:
    int convertTime(string curr, string crt) {
        int currM = ((int)curr[3]-48)*10 + ((int)curr[4]-48);   // getting current's min value
        int crtM = ((int)crt[3]-48)*10 + ((int)crt[4]-48), diff, counter=0; // getting correct's min value
        currM += ( ((int)curr[0]-48)*10 + ((int)curr[1]-48) )*60;   // getting current's hour value in mins
        crtM += (((int)crt[0]-48)*10 + ((int)crt[1])-48)*60;    // getting correct's hour value in mins
        diff = crtM - currM;
        
        counter += diff/60;
        diff -= 60 * (diff/60);
        
        counter += diff/15;
        diff -= 15 * (diff/15);
        
        counter += diff/5;
        diff -= 5 * (diff/5);
        
        counter += diff;
        diff -= diff;
        
        return counter;
    }
};