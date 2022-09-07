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
    void func1(TreeNode* curr, string &str){
        str += to_string(curr->val);
        if(curr->left || curr->right){
            str += "(";
            if(curr->left) func1(curr->left, str);
            str += ")";    
        }
        if(curr->right){
            str += "(";
            func1(curr->right, str);
            str += ")";    
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string str = "";
        func1(root, str);
        return str;
    }
};