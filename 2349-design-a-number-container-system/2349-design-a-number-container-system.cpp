class NumberContainers {
public:
    unordered_map<int, int>indInfo;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>numInfo;
    NumberContainers() {
        
    }
    
    void change(int i, int n) {
        indInfo[i] = n;
        numInfo[n].push(i);
    }
    
    int find(int n) {
        while(!(numInfo[n].empty()) && indInfo[numInfo[n].top()] != n){
            numInfo[n].pop();    
        }
        return numInfo[n].empty() ? -1 : numInfo[n].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */