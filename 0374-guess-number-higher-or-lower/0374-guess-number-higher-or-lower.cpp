/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int minl = 1, maxl = n, mid = (maxl + minl) / 2, t = guess(mid);
        while(t != 0){
            if(t == 1){
                minl = mid + 1;
            }else if(t == -1){
                maxl = mid - 1;
            }
            mid = (minl + maxl) / 2;
            t = guess(mid);
        }
        return mid;
    }
};