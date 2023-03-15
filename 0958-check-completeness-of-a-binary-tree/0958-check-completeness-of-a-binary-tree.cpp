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
    bool isCompleteTree(TreeNode* root) {
        bool shouldEnd = false;
        TreeNode *dummyPtr = new TreeNode(0);
        queue<TreeNode*>q1;
        q1.push(root);
        q1.push(NULL);
        
        while(q1.size() > 1){
            TreeNode* holder = q1.front();
            q1.pop();
            
            if(holder == NULL){
                q1.push(NULL);
                continue;
            }
            
            if(shouldEnd && holder != dummyPtr){
                return false;
            }
            
            if(holder == dummyPtr) shouldEnd = true;
            
            if(holder != dummyPtr){
                if(holder->left){
                    q1.push(holder->left);
                }else{
                    q1.push(dummyPtr);
                }

                if(holder->right){
                    q1.push(holder->right);
                }else{
                    q1.push(dummyPtr);
                }
            }
            
        }
        return true;
    }
};