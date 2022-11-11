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
    int func(TreeNode* curr, int &x, int &n2, int &n3){
        if(!curr) return 0;
        
        if(curr->val == x){
            n2 = func(curr->left, x, n2, n3);
            n3 = func(curr->right, x, n2, n3);
            return 0;
        }
        
        return func(curr->left, x, n2, n3) + func(curr->right, x, n2, n3) + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int n1 = 0, n2 = 0, n3 = 0, sp1 = 0, sp2 = 0;
        n1 = func(root, x, n2, n3);
        
        sp2 = max(n1, max(n2, n3));
        sp1 = 1 + (n1 + n2 + n3) - sp2;
        
        return sp2 > sp1;
    }
};