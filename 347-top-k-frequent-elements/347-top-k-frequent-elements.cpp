class Solution {
public:
    static bool cmp(pair<int, int>a, pair<int, int>b){
        return a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& n, int k) {
        unordered_map<int, int>m1;
        int size = n.size();
        for(int i=0;i<size;i++){
            m1[n[i]] += 1;
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>> q1;
        for(auto itr: m1){
            q1.push({itr.second, itr.first});
        }
        vector<int>v1;
        for(int i=0;i<k;i++) v1.push_back(q1.top().second), q1.pop();
        return v1;
    }
    
};