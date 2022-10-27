class Solution {
public:
    int largestOverlap(vector<vector<int>>& i1, vector<vector<int>>& i2) {
        // Idea behind the approach is that we map and relate each '1' from i1 to each '1' in i2
        // by calculating their transposing distance in form of x,y directions
        // and then all we need to do is to check the largest count for a pair from the map 'm1'
        // what the count means is that if i transpose matrix 'i1' in that x,y directions
        // than how much '1' in 'i1' will coincide with '1' in 'i2' matrix 
        int size=i1.size();
        vector<pair<int,int>>v1,v2;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i1[i][j]==1) v1.push_back({i,j});
                if(i2[i][j]==1) v2.push_back({i,j});
            }
        }
        int ans=0;
        map<pair<int,int>,int>m1;
        for(auto itr1 : v1){
            for(auto itr2 : v2){
                int a=itr1.first-itr2.first;
                int b=itr1.second-itr2.second;
                m1[{a,b}]++;
                ans=max(ans, m1[{a,b}]);
            }
        }
        return ans;
    }
};