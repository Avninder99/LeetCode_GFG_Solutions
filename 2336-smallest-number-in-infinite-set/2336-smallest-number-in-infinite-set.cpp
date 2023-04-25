class SmallestInfiniteSet {
public:
    set<int>s1;
    
    SmallestInfiniteSet() {
        for(int i=1;i<=1001;i++){
            s1.insert(i);
        }
    }
    
    int popSmallest() {
        int t = *s1.begin();
        s1.erase(t);
        return t;
    }
    
    void addBack(int num) {
        s1.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */