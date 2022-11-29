class RandomizedSet {
public:
    vector<int>rec;
    unordered_map<int, int>m1;
    int seed = 1234567;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m1.find(val) != m1.end()){
            return false;
        }
        rec.push_back(val);
        int t = rec.size();
        m1[val] = t - 1;
        return true;
    }
    
    bool remove(int val) {
        if(m1.find(val) == m1.end()){
            return false;
        }
        int t = rec[rec.size() - 1];
        m1[t] = m1[val];
        rec[m1[val]] = t;
        rec.pop_back();
        m1.erase(val);
        return true;
    }
    
    int getRandom() {
        srand(seed);
        seed += 10;
        int r = rand()%rec.size();
        int t = rec[rec.size() - 1];
        m1[t] = r;
        m1[rec[r]] = rec.size() - 1;
        rec[rec.size() - 1] = rec[r];
        rec[r] = t;
        return t;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */