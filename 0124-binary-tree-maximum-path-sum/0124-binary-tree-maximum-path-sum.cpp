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
    int func(TreeNode *curr, int &maxi){
        if(!curr){
            return 0;                               // if current node doesn't exist return 0
        }
        int l = max(func(curr->left, maxi), 0);     // Take left subtree ignore is returning sum is -ve (use 0)
        int r = max(func(curr->right, maxi), 0);    // Take left subtree ignore is returning sum is -ve (use 0)
        
        maxi = max(maxi, l + r + curr->val);        // Take path sum of current node along with both subtrees
                                                    // no need to check subtrees as i have set them to 0 if -ve
        
        int temp = max(l, r) + curr->val;           // Take current node with only 1 subtree with max sum
        maxi = max(maxi, temp);                     // compare with max val till now
        
        return max(temp, 0);                        // return the max path from our current node to subtrees
                                                    // return 0 if sum is -ve
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        func(root, maxi);
        return maxi;
    }
};