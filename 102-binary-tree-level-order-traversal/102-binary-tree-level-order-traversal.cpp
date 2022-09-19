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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v1;
        vector<int>v2;
        if(!root) return v1;
        queue<TreeNode*>q1;
        q1.push(root);
        q1.push(NULL);
        TreeNode *tptr;
        while(q1.size() > 1){
            tptr = q1.front();
            if(tptr){
                v2.push_back(tptr->val);
                if(tptr->left) q1.push(tptr->left);
                if(tptr->right) q1.push(tptr->right);
            }else{
                v1.push_back(v2);
                v2.clear();
                q1.push(NULL);
            }
            q1.pop();
        }
        v1.push_back(v2);
        return v1;
    }
};