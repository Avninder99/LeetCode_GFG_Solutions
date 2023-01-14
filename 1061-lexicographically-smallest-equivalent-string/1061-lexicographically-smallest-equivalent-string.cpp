class cnode {
public:
    char val;
    unordered_set<cnode*>links;
    cnode(char c){
        val = c;
    }
};

class Solution {
public:
    void dfs(cnode* c, vector<int>&vis, int &col){
        vis[(int)c->val - 97] = col;
        for(auto itr: c->links){
            if(vis[(int)itr->val - 97] == 0)
            dfs(itr, vis, col);
        }
    }
    string smallestEquivalentString(string s1, string s2, string bstr) {
        
        vector<int>vis(26, 0);
        unordered_map<char, cnode*>m1;
        
        for(int i=0;i<26;i++){
            cnode* t = new cnode((char)(97+i));
            m1[(char)(97+i)] = t;
        }
        
        for(int i=0;i<s1.length();i++){
            if(s1[i] == s2[i]) continue;
            m1[s1[i]]->links.insert(m1[s2[i]]);
            m1[s2[i]]->links.insert(m1[s1[i]]);
        }
        
        int col = 1;
        for(int i=0;i<26;i++){
            if(vis[i] == 0){
                dfs(m1[(char)(97+i)], vis, col);
                col++;
            }
        }
        unordered_map<int, char>mapper;
        for(int i=0;i<26;i++){
            if(mapper.find(vis[i]) != mapper.end()) continue;
            mapper[vis[i]] = (char)(97 + i);
        }
        
        for(int i=0;i<bstr.length();i++){
            int t = vis[(int)bstr[i] - 97];
            bstr[i] = mapper[t];
        }
        return bstr;
    }
};