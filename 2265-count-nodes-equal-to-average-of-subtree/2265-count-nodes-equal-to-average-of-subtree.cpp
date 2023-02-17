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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        postOrder(root, count);
        return count;
    }
private:
    pair<int, int> postOrder(TreeNode* curr, int &count){
        // returns => {number of nodes, sum of all nodes}
        if(!curr){
            return {0, 0};
        }
        int nodesNum = 1, nodesSum = curr->val;
        pair<int, int>t = postOrder(curr->left, count);
        nodesNum += t.first, nodesSum += t.second;
        
        t = postOrder(curr->right, count);
        nodesNum += t.first, nodesSum += t.second;
        
        if(nodesSum/nodesNum == curr->val){
            count++;
        }
        
        return {nodesNum, nodesSum};
    }
};