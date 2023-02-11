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
    vector<int> largestValues(TreeNode* root) {
        int maxi = INT_MIN, nextLvl = 0, lvl = 1;
        vector<int>res;
        if(!root) return res;
        
        queue<TreeNode*>q1;
        q1.push(root);
        
        while(!q1.empty()){
            TreeNode* h = q1.front();
            q1.pop();
            maxi = max(maxi, h->val);
            
            if(h->left){
                nextLvl++;
                q1.push(h->left);    
            }
            
            if(h->right){
                nextLvl++;
                q1.push(h->right);
            }
            
            lvl--;
            
            if(lvl == 0){
                res.push_back(maxi);
                maxi = INT_MIN;
                lvl = nextLvl;
                nextLvl = 0;
            }
        }
        return res;
    }
};