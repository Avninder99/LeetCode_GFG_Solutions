class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n + 1);
        for(auto itr: times){
            adj[itr[0]].push_back({itr[1], itr[2]});
        }
        vector<int>records(n + 1, 1e9);
        records[0] = 0;
        records[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, k});
        
        while(!pq.empty()){
            pair<int, int>holder = pq.top();
            pq.pop();
            int currNode = holder.second, timeTaken = holder.first;
            for(auto itr: adj[currNode]){
                if(timeTaken + itr.second < records[itr.first]){
                    records[itr.first] = timeTaken + itr.second;
                    pq.push({records[itr.first], itr.first});
                }
            }
        }
        int t = *max_element(records.begin(), records.end());
        return (t == 1e9) ? -1 : t;
    }
};