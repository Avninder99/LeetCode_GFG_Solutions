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
    void func1(vector<int>&v1, TreeNode* currNode = NULL){
        if(!currNode) return;
        func1(v1, currNode->left);
        v1.push_back(currNode->val);
        func1(v1, currNode->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v1;
        func1(v1, root);
        return v1;
    }
};