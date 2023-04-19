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
    int longestZigZag(TreeNode* root) {
        cout << root->val << endl;
        int maxi = -1;
        dfs(root, maxi);
        return maxi - 1;
    }
    pair<int, int> dfs(TreeNode* curr, int &maxi){
        if(!curr){
            return {0, 0};
        }
        int l, r;
        l = dfs(curr->left, maxi).second;
        r = dfs(curr->right, maxi).first;
        maxi = max(maxi, max(l + 1, r + 1));
        return {l + 1, r + 1};
    }
};