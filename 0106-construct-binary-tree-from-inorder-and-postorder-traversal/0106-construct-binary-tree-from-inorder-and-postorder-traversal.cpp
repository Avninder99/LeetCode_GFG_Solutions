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
    unordered_map<int, int>m1;
    TreeNode* builder(vector<int> &i, vector<int> &p, int is, int ie, int ps, int pe){
        if(is == ie || ps == pe) return NULL;
        TreeNode* newNode = new TreeNode(p[pe-1]);
        int inorderI = m1.find(p[pe-1])->second;
        int rcount = ie - inorderI - 1;
        newNode->left = builder(i, p, is, inorderI, ps, pe-1-rcount);
        newNode->right = builder(i, p, inorderI+1, ie, pe-1-rcount, pe-1);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& i, vector<int>& p) {
        int size = p.size();
        for(int j=0;j<size;j++){
            m1[i[j]] = j;
        }
        return builder(i, p, 0, size, 0, size);
    }
};