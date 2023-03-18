class BrowserHistory {
public:
    stack<string>backwardS, forwardS;
    string current = "";
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        forwardS = stack<string>();
        backwardS.push(current);
        current = url;
    }
    
    string back(int steps) {
        while(!backwardS.empty() && steps--){
            forwardS.push(current);
            current = backwardS.top();
            backwardS.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while(!forwardS.empty() && steps--){
            backwardS.push(current);
            current = forwardS.top();
            forwardS.pop();
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */