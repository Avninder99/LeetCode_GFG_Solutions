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
    int minDiffInBST(TreeNode* root) {
        int res = 1e9, prev = -100000000;
        inorder(root, res, prev);
        return res;
    }
private:
    void inorder(TreeNode* curr, int &mini, int &prev){
        if(curr->left){
            inorder(curr->left, mini, prev);
        }
        
        mini = min(mini, curr->val - prev);
        prev = curr->val;
        
        if(curr->right){
            inorder(curr->right, mini, prev);    
        }
        
        return;
    }
};