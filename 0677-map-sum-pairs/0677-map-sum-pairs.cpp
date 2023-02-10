class tNode {
public:
    int val;
    vector<tNode*>c;
    tNode(){
        c = vector<tNode*>(26, NULL);
        val = 0;
    }
};

class MapSum {
public:
    MapSum() {
        root = new tNode;
    }
    
    void insert(string k, int v) {
        tNode* curr = root;
        for(int i=0;i<k.length();i++){
            int pos = (int)k[i] - 97;
            if(curr->c[pos] == NULL){
                tNode* temp = new tNode;
                curr->c[pos] = temp;
            }
            curr = curr->c[pos];
        }
        curr->val = v;
    }
    
    int sum(string p) {
        tNode* curr = root;
        for(int i=0;i<p.length();i++){
            int pos = (int)p[i] - 97;
            if(curr->c[pos] == NULL){
                tNode* temp = new tNode;
                curr->c[pos] = temp;
            }
            curr = curr->c[pos];
        }
        return traverser(curr);
    }
private:
    tNode* root = NULL;
    int traverser(tNode* curr){
        int sum = curr->val;
        for(int i=0;i<26;i++){
            if(curr->c[i]){
                sum += traverser(curr->c[i]);
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */