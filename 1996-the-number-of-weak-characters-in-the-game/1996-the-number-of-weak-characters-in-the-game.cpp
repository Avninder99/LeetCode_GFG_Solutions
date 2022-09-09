class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] != b[0]) return a[0] < b[0];
        if(a[1] != b[1]) return a[1] > b[1];
        return true;
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        int size = p.size(), counter=0, temp=0;
        sort(p.begin(), p.end(), comp);
        for(int i=size-1;i>=0;i--){
            if(p[i][1] < temp){
                counter++;
            }
            if(p[i][1] > temp){
                temp = p[i][1];
            }
        }
        return counter;
    }
};