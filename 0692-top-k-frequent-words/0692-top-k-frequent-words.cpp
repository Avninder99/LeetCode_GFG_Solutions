class Solution {
public:
    static bool cmp(pair<int, string>a, pair<int, string>b){
        if(a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& w, int k) {
        unordered_map<string, int>m1;
        int size = w.size();
        for(int i=0;i<size;i++){
            m1[w[i]] += 1;
        }
        vector<pair<int,string>>v1;
        for(auto itr: m1){
            v1.push_back({itr.second, itr.first});
        }
        sort(v1.begin(), v1.end(), cmp);
        vector<string>v2;
        for(int i=0;i<k;i++) v2.push_back(v1[i].second);
        return v2;
    }
};