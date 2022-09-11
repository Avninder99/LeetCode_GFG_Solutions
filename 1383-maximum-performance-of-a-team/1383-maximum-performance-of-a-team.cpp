// auto comp2 = [](int &a, int &b){
//     return a < b;
// };
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i)
            ess[i] = {efficiency[i], speed[i]};
        sort(rbegin(ess), rend(ess));
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for(auto& [e, s]: ess){
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
    // code v1
//     static bool comp(vector<int>&a, vector<int>&b){
//         if(a[1] != b[1]) return a[1] > b[1];
//         return a[0] > b[0];
//     }
    
//     int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
//         int size = s.size();
//         vector<vector<int>>v1;
//         for(int i=0;i<size;i++){
//             v1.push_back({s[i], e[i]});
//         }
//         sort(v1.begin(), v1.end(), comp);
//         priority_queue<int, vector<int>, decltype(comp2)> pq(comp2);
//         int cs=0, me=1;
//         int res=0;
//         for(int i=0;i<size;i++){
//             if(pq.size() < k){
//                 pq.push(v1[i][0]);
//                 cs += v1[i][0];
//                 me = v1[i][1];
//                 res = max( res, cs*me );
//             }
//             else{
//                 int temp = pq.top();
//                 pq.pop();
//                 me = v1[i][1];
//                 pq.push(v1[i][0]);
//                 cs = cs - temp + v1[i][0];
//                 res = max(res, cs*me);
//             }
//         }
//         return res;
        
        // for(int i=size-2;i>=0;i--){
        //     if(pq.size() < k){
        //         int tme = min(me, v1[i][1]);
        //         if( cs*me < (cs + v1[i][0])*tme ){
        //             pq.push(v1[i]);
        //             cs += v1[i][0];
        //             me = tme;
        //         }
        //     }
        //     else if(pq.top()[1] < v1[i][1]){
        //         vector<int>temp = pq.top();
        //         pq.pop();
        //         int tme = min(pq.top()[1], v1[i][1]);
        //         if(cs*me <= (cs-temp[0]+v1[i][0])*tme ){
        //             me = tme;
        //             pq.push(v1[i]);
        //             cs = cs - temp[0] + v1[i][0];
        //         }else{
        //             pq.push(temp);
        //         }
        //     }
        //     pq.push(v1[i]);
        // }
        // // while(!pq.empty()){
        // //     holder.push_back(pq.top());
        // //     pq.pop();
        // // }
        // // for(int i=0;i<;i++)
        // return cs*me;
    // }
};