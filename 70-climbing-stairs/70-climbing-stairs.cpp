class Solution {
public:
    int climbStairs(int n) {
        // Optimal Approach
        if(n <= 2) return n;
        int next=2, next2=1, curr;
        for(int i=n-3;i>=0;i--){
            curr = next + next2;
            next2 = next;
            next = curr;
        }
        return curr;
    }
};