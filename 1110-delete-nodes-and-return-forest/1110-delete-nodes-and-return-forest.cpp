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
    // void recorder(TreeNode *curr){
    //     if(!curr){
    //         return;
    //     }
    //     m1[curr->val] = curr;
    //     recorder(curr->left);
    //     recorder(curr->right);
    //     return;
    // }
    void traverser(TreeNode *curr, vector<TreeNode*>&rec, unordered_set<int>&s1){
        if(!curr){
            return;
        }
        traverser(curr->left, rec, s1);
        traverser(curr->right, rec, s1);
        
        if(curr->left && s1.count(curr->left->val) == 1){
            delete curr->left;
            curr->left = NULL;
        }
        if(curr->right && s1.count(curr->right->val) == 1){
            delete curr->right;
            curr->right = NULL;
        }
        
        if(s1.count(curr->val) == 1){
            if(curr->left) rec.push_back(curr->left);
            if(curr->right) rec.push_back(curr->right);
        }
        
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        unordered_set<int>s1(td.begin(), td.end());
        vector<TreeNode*>rec;
        traverser(root, rec, s1);
        if(s1.count(root->val) == 0){
            rec.push_back(root);
        }
        return rec;
    }
};