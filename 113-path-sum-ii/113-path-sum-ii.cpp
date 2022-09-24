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
    int sum;
    vector<int>v1;
    vector<vector<int>>a1;
    void arr_create(){
        int size = v1.size(), temp_sum = 0;
        for(int i=0;i<size;i++){
            temp_sum += v1[i];
        }
        if(temp_sum == sum){
            a1.push_back(v1);    
        }
    }
    void bt_paths(TreeNode *current_node = NULL){
        if(!current_node) return;
        v1.push_back(current_node->val);

        if(!current_node->left && !current_node->right){
            arr_create();
        }
        bt_paths(current_node->left);
        bt_paths(current_node->right);
        v1.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* current_node, int targetSum) {
        sum = targetSum;
        bt_paths(current_node);
        return a1;
    }
};