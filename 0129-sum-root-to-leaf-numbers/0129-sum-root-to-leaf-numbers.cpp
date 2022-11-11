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
    void func(TreeNode* curr, vector<int>holder, int &sum){
        holder.push_back(curr->val);
        if(!curr->left && !curr->right) {
            int t=0, mul=1;
            for(int i=holder.size() - 1 ; i >= 0 ; i--){
                t += holder[i] * mul;
                if(mul < 1000000000) mul *= 10;
            }
            sum += t;
            return;
        }
        if(curr->left) func(curr->left, holder, sum);
        if(curr->right) func(curr->right, holder, sum);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<int>holder;
        func(root, holder, sum);
        return sum;
    }
};