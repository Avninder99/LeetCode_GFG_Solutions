// auto comp2 = [](int &a, int &b){
//     return a < b;
// };
class Solution {
public:
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<vector<int>>v1;
        for(int i=0;i<n;i++){
            v1.push_back({e[i],s[i]});
        }
        sort(rbegin(v1), rend(v1));
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int cs=0, me=1, res=0;
        for(int i=0;i<n;i++){
            pq.emplace(v1[i][1]);
            cs += v1[i][1];
            if(pq.size() > k){
                cs -= pq.top();
                pq.pop();
                
            }
            res = max( res, cs*v1[i][0] );
        }
        return res%1000000007;
    }
    
    // code v1
    // static bool comp(vector<int>&a, vector<int>&b){
    //     if(a[1] != b[1]) return a[1] > b[1];
    //     return a[0] > b[0];
    // }
    // int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
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
    // }
};