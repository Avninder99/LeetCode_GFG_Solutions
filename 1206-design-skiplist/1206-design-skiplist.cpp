class snode {
public:
    int val;
    snode *next=NULL, *down=NULL;
    snode(int v){
        val = v;
    }
};
class Skiplist {
public:
    unordered_map<int, snode*>sentinentNodes;
    Skiplist() {
        sentinentNodes[0] = new snode(-1);
        for(int i=1;i<10;i++){
            sentinentNodes[i] = new snode(-1);
            sentinentNodes[i]->down=sentinentNodes[i-1];
        }
    }
    
    bool search(int num) {
        snode* t = sentinentNodes[9];
        for(int i=9;i>=0;i--){
            while(t->next && t->next->val <= num){
                if(t->val == num) return true;
                t = t->next;
                if(t->val == num) return true;
            }
            t = t->down;
        }
        return false;
    }
    
    void add(int num) {
        vector<snode*>temp(10);
        snode* t = sentinentNodes[9];
        // cout << t->val;
        for(int i=9;i>=0;i--){
            // snode* t = sentinentNodes[i];
            while(t->next && t->next->val <= num){
                t = t->next;
            }
            if(i == 0){
                snode *nS = new snode(num);
                nS->next = t->next;
                t->next = nS;
                t = nS;
                int j=0;
                while(j < 9){
                    j++;
                    if(!flip()) break;
                    else{
                        snode *nS2 = new snode(num);
                        nS2->down = t;
                        nS2->next = temp[j]->next;
                        temp[j]->next = nS2;
                        t = nS2;
                    }
                }
                return;
            }else{
                temp[i] = t;
                t = t->down;    
            }
        }
        
    }
    
    bool erase(int num) {
        snode* t = sentinentNodes[9];
        bool found=false;
        for(int i=9;i>=0;i--){
            while(t->next && t->next->val < num){
                t = t->next;
            }
            if(t->next && t->next->val == num){
                found=true;
                snode *t2 = t->next;
                t->next = t->next->next;
                delete t2;
            }
            t = t->down;
        }
        return found;
    }
    bool flip(){
        // srand(time(0));
        return (rand()%3);
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */