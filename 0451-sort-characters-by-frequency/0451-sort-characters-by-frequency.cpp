class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>m1;
        int size = s.size();
        for(int i=0;i<size;i++){
            if(m1.find(s[i]) != m1.end()) m1[s[i]] += 1;
            else m1[s[i]] = 1;
        }
        s="";

        priority_queue<pair<int, char>>pq;

        for(auto i: m1){
            pq.push({i.second, i.first});
        }
        while(!pq.empty()){
            int j = pq.top().first;
            char ch = pq.top().second;
            for(int i=0;i<j;i++){
                s += ch;
            }
            pq.pop();
        }
        return s;
    }
};