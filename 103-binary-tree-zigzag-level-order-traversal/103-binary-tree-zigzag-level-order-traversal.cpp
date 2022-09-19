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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v1;
        vector<int>v2;
        if(!root) return v1;
        deque<TreeNode*>q1;
        bool alt = false;
        q1.push_back(root);
        q1.push_back(NULL);
        TreeNode *tptr;
        while(q1.size() > 1){
            if(alt){
                tptr = q1.back();
                if(tptr){
                    v2.push_back(tptr->val);
                    if(tptr->right) q1.push_front(tptr->right);
                    if(tptr->left) q1.push_front(tptr->left);
                }else{
                    v1.push_back(v2);
                    v2.clear();
                    q1.push_back(NULL);
                    alt = false;
                }
                q1.pop_back();
            }else{
                tptr = q1.front();
                if(tptr){
                    v2.push_back(tptr->val);
                    if(tptr->left) q1.push_back(tptr->left);
                    if(tptr->right) q1.push_back(tptr->right);
                }else{
                    v1.push_back(v2);
                    v2.clear();
                    q1.push_front(NULL);
                    alt = true;
                }
                q1.pop_front();    
            }
            
        }
        v1.push_back(v2);
        return v1;
    }
};