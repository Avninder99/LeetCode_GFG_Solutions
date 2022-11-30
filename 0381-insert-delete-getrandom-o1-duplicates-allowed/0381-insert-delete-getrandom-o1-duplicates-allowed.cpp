class RandomizedCollection {
public:
    vector<int>rec;
    unordered_map<int, unordered_set<int>>m1;
    int seed = 1234567;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        int t = rec.size();
        rec.push_back(val);
        bool retVal = false;
        
        if(m1.find(val) == m1.end() || m1[val].size() == 0){
            retVal = true;
        }
        
        m1[val].insert(t);
        
        return retVal;
    }
    
    bool remove(int val) {
        if(m1.find(val) == m1.end() || m1[val].size() == 0){
            return false;
        }
        
        if(rec[rec.size() - 1] == val){
            m1[val].erase(rec.size() - 1);
            rec.pop_back();
            return true;
        }
        
        int targetI = *(m1[val].begin());
        
        int lVal = rec[rec.size() - 1];
        m1[lVal].erase(rec.size() - 1);
        
        m1[val].erase(targetI);
        
        m1[lVal].insert(targetI);
        rec[targetI] = lVal;
        
        rec.pop_back();
        
        return true;
    }
    
    int getRandom() {
        srand(seed);
        seed += 10;
        return rec[rand()%rec.size()];
    }
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */