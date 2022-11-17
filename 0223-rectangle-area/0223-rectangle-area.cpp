class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1, a2, xol, yol, aol;
        a1 = (ax2 - ax1) * (ay2 - ay1);               // area of the first rectangle
        a2 = (bx2 - bx1) * (by2 - by1);               // area of the second rectangle 
        xol = max(min(ax2,bx2) - max(ax1,bx1),0);     // overlap of sides along x-axis
        yol = max(min(ay2,by2) - max(ay1,by1),0);     // overlap of sides along y-axis
        aol = xol * yol;                              // area of the overlap region
        return a1 + a2 - aol;
    }
};