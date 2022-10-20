class LRUCache {
public:
    int cap;
    queue<pair<int,pair<int,int>>>q1;
    unordered_map<int, pair<int,int>>m1; // key, value, count
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m1.find(key) == m1.end()) return -1;
        m1[key].second += 1;
        q1.push({key,{m1[key].first,m1[key].second}});
        while(m1.size() > cap){
            if(q1.front().second.first == m1[q1.front().first].first && q1.front().second.second == m1[q1.front().first].second){
                m1.erase(q1.front().first);
            }
            q1.pop();
        }
        return m1[key].first;
    }
    
    void put(int key, int value) {
        if(m1.find(key) != m1.end()) m1[key] = {value, m1[key].second+1};
        else m1[key] = {value, 1};
        q1.push({key,{value,m1[key].second}});
        while(m1.size() > cap){
            if(q1.front().second.first == m1[q1.front().first].first && q1.front().second.second == m1[q1.front().first].second){
                m1.erase(q1.front().first);
            }
            q1.pop();
        }
        // if(size < cap) size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */