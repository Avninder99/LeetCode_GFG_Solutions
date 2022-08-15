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
    int maxDepth(Node* root) {
        if(!root) return 0;
        int len1 = (root->children).size(), max = 0, temp=0;
        for(int i=0;i<len1;i++){
            temp = maxDepth(root->children[i]);
            if(temp > max){
                max = temp;
            }
        }
        return max + 1;
    }
};