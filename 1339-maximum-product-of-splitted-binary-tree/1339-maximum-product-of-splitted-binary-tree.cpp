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
    // O(N) - Time complexity
    int maxProduct(TreeNode* root) {
        long long int total = calc(root), prod = 1;
        pcalc(root, total, prod);
        return (prod % 1000000007);
    }
private:
    int calc(TreeNode *curr){
        if(!curr) return 0;
        return calc(curr->left) + calc(curr->right) + curr->val;
    }
    int pcalc(TreeNode *curr, long long int &total, long long int &p){
        if(!curr) return 0;
        
        int lt = pcalc(curr->left, total, p), rt = pcalc(curr->right, total, p);
        long long int lr = total - lt, rr = total - rt, prod;
        
        prod = (total - lt) * lt;
        if(prod > p){
            p = prod;
        }
        
        prod = (total - rt) * rt;
        if(prod > p) {
            p = prod;
        }
        return lt + rt + curr->val;
    }
};