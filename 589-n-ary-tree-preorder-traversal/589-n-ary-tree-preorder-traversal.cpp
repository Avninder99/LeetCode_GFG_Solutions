/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void func(Node* curr, vector<int>&v1){
        if(!curr) return;
        v1.push_back(curr->val);
        for(int i=0;i<curr->children.size();i++){
            func(curr->children[i], v1);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        vector<int>v1;
        func(root, v1);
        return v1;
    }
};