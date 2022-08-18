class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& n) {
        int size = n.size(), j;
        vector<int>v1 (size, -1);
        stack<pair<int,int>>s1;
        s1.push({n[size-1], size-1});
        for(int i=0;i<2*size-2;i++){
            j = i%size;
            while(!s1.empty() && n[j] > s1.top().first){
                v1[s1.top().second] = n[j];
                s1.pop();
            }
            s1.push({n[j], j});
        }
        return v1;
    }
};