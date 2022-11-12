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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        holder = make_pair(root, -1);
        func(root, 0);
        return holder.first;
    }
private:
    pair<TreeNode* , int> holder;
    int func(TreeNode* curr, int d){
        if(!curr){
            return d-1;
        }
        
        int l = func(curr->left, d+1);
        int r = func(curr->right, d+1);
        
        if(l == r && l >= holder.second){
            holder = make_pair(curr, l);
        }
        
        return max(l, r);
    }
};