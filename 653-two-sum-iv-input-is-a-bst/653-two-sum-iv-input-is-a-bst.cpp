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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>l,r;
        
        TreeNode *lnode=root, *rnode=root;
        while(lnode->left || rnode->right){
            if(lnode->left){
                l.push(lnode);
                lnode = lnode->left;
            }
            if(rnode->right){
                r.push(rnode);
                rnode = rnode->right;
            }
        }
        
        int sum;
        while(!l.empty() || !r.empty()){
            sum = lnode->val + rnode->val;
            if(lnode == rnode) return false;
            if(sum == k) return true; 
            if(sum > k){
                if(rnode->left){
                    rnode = rnode->left;
                    while(rnode->right){
                        r.push(rnode);
                        rnode = rnode->right;
                    }
                }else{
                    rnode = r.top();
                    r.pop();
                }
            }else{
                if(lnode->right){
                    lnode = lnode->right;
                    while(lnode->left){
                        l.push(lnode);
                        lnode = lnode->left;
                    }
                }else{
                    lnode = l.top();
                    l.pop();
                }
            }
        }
        return false;
    }
};