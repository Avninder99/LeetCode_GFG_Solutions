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
    
    int func1(TreeNode* curr, int k, int &counter){
        if(!curr) return -1;
        
        int left = func1(curr->left, k, counter);
        if(left != -1) return left;
        
        counter += 1;
        if(counter == k) return curr->val;
        
        int right = func1(curr->right, k, counter);
        if(right != -1) return right;
        
        return -1;
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int counter=0;
        return func1(root, k, counter);
        
    }
};