class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int pEnd = points[0][1], count = 1;
        for(int i=1;i<points.size();i++){
            if(points[i][0] > pEnd){
                count++;
                pEnd = points[i][1];
            }else{
                pEnd = min(pEnd, points[i][1]);
            }
        }
        return count;
    }
};