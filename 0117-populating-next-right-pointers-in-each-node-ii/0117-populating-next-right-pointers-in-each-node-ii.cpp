/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    queue<Node*>q1;
    Node* connect(Node* root) {
        if(!root) return NULL;
        q1.push(NULL);
        q1.push(root);
        
        Node* prev_node = NULL;
        
        while(q1.size() > 1){
            Node *temp = q1.front();
            if(temp == NULL){
                q1.push(NULL);
            }else{
                if(prev_node){
                    prev_node->next = temp;
                }
                if(temp->left) q1.push(temp->left);
                if(temp->right) q1.push(temp->right);
            }
            prev_node = q1.front();
            q1.pop();
        }
        return root;
    }
};