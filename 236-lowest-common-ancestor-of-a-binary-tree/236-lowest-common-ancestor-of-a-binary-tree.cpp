/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *LCA = NULL;
    bool func(TreeNode *curr, TreeNode *p, TreeNode *q){
        if(!curr) return false;
        bool t = false;
        if(curr == p || curr == q){
            t = true;
        }
        bool l = func(curr->left, p, q);
        bool r = func(curr->right, p, q);
        int t2 = (int)t + (int)l + (int)r;
        if(t2 == 2) LCA = curr;
        else if(t2 == 1) return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(root, p, q);
        return LCA;
    }
};