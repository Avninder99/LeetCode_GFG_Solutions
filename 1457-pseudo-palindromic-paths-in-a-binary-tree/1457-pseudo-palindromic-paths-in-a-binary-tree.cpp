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
    
    void traverser(TreeNode* curr, int &counter, unordered_set<int>&s1){
        if(!curr) return;
        bool e;
        if(s1.count(curr->val)){
            s1.erase(curr->val);
            e = true;
        }else{
            s1.insert(curr->val);
            e = false;
        }
        if(!curr->left && !curr->right){
            if(s1.size() <= 1) counter++;
        }else{
            traverser(curr->left, counter, s1);
            traverser(curr->right, counter, s1);    
        }
        if(e) s1.insert(curr->val); 
        else s1.erase(curr->val);
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int>s1;
        int counter=0;
        traverser(root, counter, s1);
        return counter;
    }
};