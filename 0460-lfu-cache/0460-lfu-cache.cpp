class node {
    public:
        int key, val, counter=0;
        node *next=NULL, *prev=NULL;
        node(int k, int v, int c){
            key = k, val = v, counter = c;
        }
};

class dll {
    public:
        node *head=NULL, *tail=NULL;
        node* addF(int k, int v, int c, unordered_map<int, node*> &nodeM){
            node *t = new node(k,v,c);
            nodeM[k] = t;
            t->next = head;
            if(head) head->prev = t;
            head = t;
            if(!tail) tail = t;
            return t;
        }
        void deleteB(unordered_map<int, node*> &nodeM){
            if(!tail) return;
            node* t = tail;
            tail = tail->prev;
            if(!tail) head = NULL;
            else tail->next = NULL;
            nodeM.erase(t->key);
            delete t;
        }
};

class LFUCache {
public:
    int cap, size=0;
    unordered_map<int, dll*> freqM;
    unordered_map<int, node*> nodeM;
    LFUCache(int c) {
        cap = c;
    }
    
    int get(int key) {
        if(nodeM.find(key) == nodeM.end()) return -1;
        int v = nodeM[key]->val, c = nodeM[key]->counter;
        
        if(freqM[c]->head == nodeM[key]){
            freqM[c]->head = freqM[c]->head->next;
        }
        if(freqM[c]->tail == nodeM[key]){
            freqM[c]->tail = freqM[c]->tail->prev;
        }
        if(nodeM[key]->next) nodeM[key]->next->prev = nodeM[key]->prev;
        if(nodeM[key]->prev) nodeM[key]->prev->next = nodeM[key]->next;
        
        c++;
        if(freqM.find(c) == freqM.end()) freqM[c] = new dll;
        delete nodeM[key];
        nodeM[key] = freqM[c]->addF(key, v, c, nodeM);
        
        return nodeM[key]->val;
    }
    
    void put(int key, int v) {
        if(cap == 0) return;
        
        if(nodeM.find(key) != nodeM.end()){
            int c = nodeM[key]->counter;
            if(freqM[c]->head == nodeM[key]){
                freqM[c]->head = freqM[c]->head->next;
            }
            if(freqM[c]->tail == nodeM[key]){
                freqM[c]->tail = freqM[c]->tail->prev;
            }
            if(nodeM[key]->next) nodeM[key]->next->prev = nodeM[key]->prev;
            if(nodeM[key]->prev) nodeM[key]->prev->next = nodeM[key]->next;
            c++;
            if(freqM.find(c) == freqM.end()) freqM[c] = new dll;
            delete nodeM[key];
            nodeM[key] = freqM[c]->addF(key, v, c, nodeM);
            return;
        }else{
            if(freqM.find(1) == freqM.end()) freqM[1] = new dll;
            if(size == cap){
                for(int i=1;i<20000;i++){
                    if(freqM[i]->head){
                        freqM[i]->deleteB(nodeM);
                        break;
                    }
                }
                size--;
            }
            size++;
            nodeM[key] = freqM[1]->addF(key, v, 1, nodeM);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */