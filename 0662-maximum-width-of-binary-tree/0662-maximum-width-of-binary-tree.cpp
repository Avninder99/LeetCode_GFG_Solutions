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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q1;
        q1.push({root, 0});
        q1.push({NULL, -1});
        int f = INT_MAX, l = 0, maxW = 0;
        long long int m = (long long int)INT_MAX + 1;
        TreeNode* curr = NULL;
        
        while(!q1.empty()){
            if(q1.front().first == NULL){
                maxW = max(maxW, l - f + 1);
                q1.pop();
                f = INT_MAX, l = 0;
                if(!q1.empty()){
                    q1.push({NULL, -1});
                }
                continue;
            }
            
            long long int i = q1.front().second;
            curr = q1.front().first;
            q1.pop();
            
            if(i < f){
                f = i;
            }
            if(i > l){
                l = i;
            }
            
            if(curr->left){
                q1.push({curr->left, (2*i + 1)%m});
            }
            
            if(curr->right){
                q1.push({curr->right, (2*i + 2)%m});
            }
        }
        return maxW;
    }
};
