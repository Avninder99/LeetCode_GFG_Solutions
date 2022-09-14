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
    unordered_set<int>s1;
    int counter=0;
    void traverser(TreeNode* curr){
        if(!curr) return;
        if(s1.count(curr->val)) s1.erase(curr->val);
        else s1.insert(curr->val);
        if(!curr->left && !curr->right){
            if(s1.size() <= 1) counter++;
        }else{
            traverser(curr->left);
            traverser(curr->right);    
        }
        if(s1.count(curr->val)) s1.erase(curr->val);
        else s1.insert(curr->val);
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        traverser(root);
        return counter;
    }
};