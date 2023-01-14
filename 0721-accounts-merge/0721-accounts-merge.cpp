class node {
public:
    string eval, name;
    vector<node*>relE;
    node(string val, string n){
        eval = val;
        name = n;
    }
};

class Solution {
public:
    void dfs(node* curr, unordered_map<string, node*>&mtn, unordered_set<string>&vis, vector<vector<string>>&ans, vector<string>&temp){
        vis.erase(curr->eval);
        temp.push_back(curr->eval);
        for(auto itr: curr->relE){
            if(vis.count(itr->eval)){
                dfs(itr, mtn, vis, ans, temp);
            }
        }
        return;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        
        unordered_map<string, node*>mailToNode;
        unordered_set<string>vis;
        
        for(auto itr: acc){
            node* main = NULL;
            if(mailToNode.find(itr[1]) == mailToNode.end()){
                main = new node(itr[1], itr[0]);
                mailToNode[itr[1]] = main;
                vis.insert(itr[1]);
            }else{
                main = mailToNode[itr[1]];
            }
            for(int i=2;i<itr.size();i++){
                vis.insert(itr[i]);
                if(mailToNode.find(itr[i]) == mailToNode.end()){
                    node* t = new node(itr[i], itr[0]);
                    main->relE.push_back(t);
                    t->relE.push_back(main);
                    mailToNode[itr[i]] = t;
                }else{
                    main->relE.push_back(mailToNode[itr[i]]);
                    mailToNode[itr[i]]->relE.push_back(main);
                }
            }
        }
        
        vector<vector<string>>ans;
        vector<string>t;
        while(!vis.empty()){
            string h = *vis.begin();
            dfs(mailToNode[h], mailToNode, vis, ans, t);
            sort(t.rbegin(), t.rend());
            t.push_back(mailToNode[h]->name);
            reverse(t.begin(), t.end());
            ans.push_back(t);
            t.clear();
        }
        
        return ans;
    }
};