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
    void dfs(TreeNode *curr, vector<int>&rec){
        if(!curr) return;
        rec.push_back(curr->val);
        dfs(curr->left, rec);
        dfs(curr->right, rec);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>rec;
        dfs(root, rec);
        return rec;
    }
};