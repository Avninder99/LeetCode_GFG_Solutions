/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *head;
    int func(TreeNode *curr, int &t){
        if(!curr) return 0;
        
        // store return values for child nodes
        int l = func(curr->left, t), r = func(curr->right, t);
        
        // reset the pointers to be on safe side and remove pointer for deleted childrens is any
        if(l == 0){
            curr->left = NULL;
        }
        if(r == 0){
            curr->right = NULL;
        }
        
        // if both children are NULL then check if current node is equal to t
        // if yes then delete it
        
        if(l + r == 0 && curr->val == t){
            if(curr != head) delete curr;
            return 0;
        }
        return 1;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        head = root;
        if(!func(root, t)) return NULL;
        return root;
    }
};