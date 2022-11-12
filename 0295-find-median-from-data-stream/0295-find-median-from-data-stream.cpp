class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void balancer(){
        if(r.size() == l.size() || r.size() == l.size() + 1) return;
        else{
            if(l.size() > r.size()){
                r.push(l.top());
                l.pop();
            }else{
                l.push(r.top());
                r.pop();
            }
        }
        return;
    }
    
    void addNum(int num) {
        if(size < 1) r.push(num);
        else{
            if(num < r.top()){
                l.push(num);
            }else{
                r.push(num);
            }
            balancer();
        }
        size++;
    }
    
    double findMedian() {
        if(size%2){     // for odd size
            if(l.size() > r.size()) return l.top();
            return r.top();
        }else{
            return (double)(l.top() + r.top()) / 2;
        }
    }
private:
    int size=0;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */