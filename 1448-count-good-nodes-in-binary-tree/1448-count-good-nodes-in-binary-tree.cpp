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
    void func1(TreeNode* curr, int &counter, int maxTillNow){
        if(!curr) return;
        if(curr->val >= maxTillNow){
            maxTillNow = curr->val;
            counter++;
        }
        func1(curr->left, counter, maxTillNow);
        func1(curr->right, counter, maxTillNow);
        return;
    }
    int goodNodes(TreeNode* root) {
        int counter=0;
        func1(root, counter, -100000);
        return counter;
    }
};