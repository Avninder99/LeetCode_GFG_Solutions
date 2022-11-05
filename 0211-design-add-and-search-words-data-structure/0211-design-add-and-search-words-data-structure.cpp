class tNode {
    public:
        vector<tNode*>ch = vector<tNode*>(26, NULL);
        bool e = false;
};

class WordDictionary {
public:
    tNode* root = NULL;
    WordDictionary() {
        root = new tNode;
    }
    
    void addWord(string w) {
        tNode* curr = root;
        int len = w.length();
        for(int i=0;i<len;i++){
            if(curr->ch[w[i]-'a'] == NULL){
                tNode* t = new tNode;
                curr->ch[w[i]-'a'] = t;
            }
            curr = curr->ch[w[i]-'a'];
        }
        curr->e = true;
    }
    
    bool search(string w) {
        return func(w, root, 0);
    }
    
private:
    bool func(string w, tNode* curr, int st){
        int len = w.length();
        for(int i=st;i<len;i++){
            if(w[i] == '.'){
                // for '.' on last index
                if(i == len) return curr->e;
                // for handling '.' on all other indexes
                for(int j=0;j<26;j++) if(curr->ch[j] && func(w, curr->ch[j], i+1)) return true;
                return false;
            }
            else if(curr->ch[w[i]-'a'] == NULL) return false;
            curr = curr->ch[w[i]-'a'];
        }
        return curr->e;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */