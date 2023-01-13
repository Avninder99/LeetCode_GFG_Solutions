/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr, Node* duplicate, unordered_set<int>&vis, unordered_map<int, Node*>&rec){
        vis.insert(curr->val);
        for(auto itr: curr->neighbors){
            if(vis.count(itr->val)){
                duplicate->neighbors.push_back(rec[itr->val]);
            }else{
                Node* t = new Node(itr->val);
                rec[itr->val] = t;
                duplicate->neighbors.push_back(t);
                dfs(itr, t, vis, rec);
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        Node* curr = new Node;
        unordered_set<int>vis;
        unordered_map<int, Node*>rec;
        
        Node* t = new Node(node->val);
        rec[node->val] = t;
        
        dfs(node, t, vis, rec);
        return t;
    }
};