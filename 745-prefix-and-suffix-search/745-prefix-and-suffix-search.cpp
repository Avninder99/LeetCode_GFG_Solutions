class WordFilter {
public:
    unordered_map<string, int>m1;
    
    WordFilter(vector<string>& words) {     // fired at start
        int size = words.size(), sizeW;
        for(int i=0;i<size;i++){
            string l = "";
            sizeW = words[i].size();
            for(int j=0;j<sizeW;j++){
                l += words[i][j];
                string r = "";
                for(int k=sizeW-1;k>=0;k--){
                    r = words[i][k] + r;    // add character in reverse order
                    m1[l + "$" + r] = i;
                }
            }
        }
    }
    int f(string prefix, string suffix) {
        auto itr = m1.find( prefix + "$" + suffix );
        if(itr != m1.end()){
            return itr->second;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */