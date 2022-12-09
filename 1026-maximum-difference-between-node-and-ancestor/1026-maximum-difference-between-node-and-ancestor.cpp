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
    void func(TreeNode *curr, int &maxDiff, int minL, int maxL){
        if(!curr) return;
        
        int rec = max(abs(maxL - curr->val), abs(curr->val - minL));
        maxDiff = max(maxDiff, rec);
        
        if(curr->val > maxL){
            maxL = curr->val;
        }else if(curr->val < minL){
            minL = curr->val;
        }
        
        func(curr->left, maxDiff, minL, maxL);
        func(curr->right, maxDiff, minL, maxL);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        func(root, maxDiff, root->val, root->val);
        return maxDiff;
    }
};