class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        // Intuition
        
        // let each column just look for the max width box it can make of it's own height
        // for this we need to find the first smaller height on left and right side
        // then using those we can just calculate the area of this one rectangle
        
        // Now we need to do above solution for each column
        // but if we go completely brute force in finding the next smaller node in
        // both left and right side then our solution would take O(N * N) -> O(N^2) time
        // which will give us TLE in the longest case mentioned in our constraints
        
        // To solve this i have used monotonic stack approach for finding the next smaller
        // heights in left and right directions seprately and store them
        // then using above information we compute area for each rectangle for each height
        // So time complexity will be O(N + N + N) -> O(3 * N) -> O(N)
        
        int size = h.size();
        vector<int>l(size), r(size);
        stack<pair<int, int>>st1;    // value, index
        for(int i=0;i<size;i++){
            while(!st1.empty() && st1.top().first > h[i]){
                r[st1.top().second] = i;
                st1.pop();
            }
            st1.push(make_pair(h[i], i));
        }
        while(!st1.empty()){
            r[st1.top().second] = size;
            st1.pop();
        }
        for(int i=size-1;i>=0;i--){
            while(!st1.empty() && st1.top().first > h[i]){
                l[st1.top().second] = i;
                st1.pop();
            }
            st1.push(make_pair(h[i], i));
        }
        while(!st1.empty()){
            l[st1.top().second] = -1;
            st1.pop();
        }
        int maxi = 0, t;
        for(int i=0;i<size;i++){
            t = h[i] * ((i - l[i] - 1) + 1 + (r[i] - i - 1));
            maxi = max(maxi, t);
        }
        return maxi;
    }
};