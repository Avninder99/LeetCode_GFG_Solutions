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
    // -1 for NULL, 0 for not monitored, 1 for monitored and 2 for camera node
    int counter = 0;
    int traverser(TreeNode *curr = NULL){
        if(!curr) return -1;
        int l = traverser(curr->left);
        int r = traverser(curr->right);
        
        if(l==-1 && r==-1) return 0;
        else if(l==0 || r==0){
            counter++;
            return 2;
        }else if(l==2 || r==2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        
        int r = traverser(root);
        if(r == 0) counter++;
        if(counter == 0) return 1;
        return counter;
    }
};