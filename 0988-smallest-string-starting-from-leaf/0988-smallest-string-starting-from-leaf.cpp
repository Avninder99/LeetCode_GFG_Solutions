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
    // see notes for my bottom-up approach (it fails for last test case)
    // in this question only top-down appears to work
    string smallestFromLeaf(TreeNode* r, string s = "") {
        s = string(1, 'a' + r->val) + s;
        return r->left == r->right ? s : min(r->left ? smallestFromLeaf(r->left, s) : "|", 
            r->right ? smallestFromLeaf(r->right, s) : "|");
    }
};