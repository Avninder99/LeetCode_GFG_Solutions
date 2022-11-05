class tNode {
    public:
        vector<tNode*>ch = vector<tNode*>(26, NULL);
        bool e = false;
};

class Trie {
public:
    tNode* root = NULL;
    Trie() {
        root = new tNode;
    }
    
    void insert(string w) {
        tNode* curr = root;
        for(int i=0;i<w.length();i++){
            if(curr->ch[w[i]-'a'] == NULL){
                tNode* t = new tNode;
                curr->ch[w[i]-'a'] = t;
            }
            curr = curr->ch[w[i]-'a'];
        }
        curr->e = true;
    }
    
    bool search(string w) {
        tNode* curr = root;
        for(int i=0;i<w.length();i++){
            if(curr->ch[w[i]-'a'] == NULL) return false;
            curr = curr->ch[w[i]-'a'];
        }
        return curr->e;
    }
    
    bool startsWith(string p) {
        tNode* curr = root;
        for(int i=0;i<p.length();i++){
            if(curr->ch[p[i]-'a'] == NULL) return false;
            curr = curr->ch[p[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */