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
    bool func1(TreeNode* curr){
        if(!curr) return false;
        
        bool left = func1(curr->left);
        if(!left) curr->left = NULL;
        bool right = func1(curr->right);
        if(!right) curr->right = NULL;
        
        if(left || right || curr->val == 1) return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool check = func1(root);
        if(check) return root;
        return NULL;
    }
};