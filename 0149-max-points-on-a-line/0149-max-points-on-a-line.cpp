class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int size = p.size();
        if(size <= 2) return size;
        unordered_map<double,int> m1;
        int ans = 0;
        double s;
        for(auto itr : p){
            m1.clear();
            int x1 = itr[0], y1 = itr[1], x2, y2;
            for(auto itr2 : p){   
                if(itr == itr2) continue;
                x2 = itr2[0], y2 = itr2[1];
                if(x2 == x1){
                    s = INT_MAX;
                }else{
                    s = (double)(y2 - y1)/(x2 - x1);   
                }
                m1[s]++;
                ans = max(ans, m1[s]);
            }
        }
        return ans+1;
    }
        
        // second approach
//         map<pair<double, double>, set<int>>m1;
//         for(int i=0;i<p.size();i++){
//             for(int j=0;j<p.size();j++){
//                 if(i != j){
                    
//                     if(p[i][0] != p[j][0]){
//                         double m = (double)(p[j][1] - p[i][1]) / (p[j][0] - p[i][0]);
//                         double c = -1 * (m * p[j][0]);
//                         m1[make_pair(m, c)].insert(i);
//                         m1[make_pair(m, c)].insert(j);
//                     }else{
                        
//                         m1[make_pair(INT_MAX, p[j][0])].insert(i);
//                         m1[make_pair(INT_MAX, p[j][0])].insert(j);
//                     }
                    
                    
//                 }
//             }
            
//         }
//         int res = 2;
//         for(auto itr = m1.begin(); itr != m1.end(); itr++){
//             if(itr->second.size() > res){
//                 res = itr->second.size();
//             }
//         }
//         return res;
    
};