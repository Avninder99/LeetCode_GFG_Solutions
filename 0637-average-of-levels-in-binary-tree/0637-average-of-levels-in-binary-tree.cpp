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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q1;
        bool runner = true;
        double avg, sum=0, count=0;
        vector<double>v1;
        q1.push(root);
        q1.push(NULL);
        while(runner){
            if(q1.size() == 1) runner = false;
            if(q1.front() == NULL){
                q1.pop();
                q1.push(NULL);
                avg = (double)sum/(double)count;
                v1.push_back(avg);
                sum=0, count=0;
            }else{
                if(q1.front()->left) q1.push(q1.front()->left);
                if(q1.front()->right) q1.push(q1.front()->right);
                count++;
                sum += q1.front()->val;
                q1.pop();
            }
        }
        return v1;
    }
};