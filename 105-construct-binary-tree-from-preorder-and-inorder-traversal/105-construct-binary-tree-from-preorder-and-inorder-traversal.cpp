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
    unordered_map<int, int>m1; // <value, index>
    TreeNode* builder(vector<int>& p, vector<int>& i, int size, int ps=-1, int pe=-1, int is=-1, int ie=-1) {
        
        if(is == ie || ps == pe) return NULL;
        
        TreeNode* newNode = new TreeNode(p[ps]);
        
        int inorderI = m1.find(p[ps])->second;
        int lcount = inorderI - is;
        
        newNode->left = builder(p, i, size, ps+1, ps+lcount+1, is, inorderI);
        newNode->right = builder(p, i, size, ps+lcount+1, pe, inorderI+1, ie);
        
        return newNode;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        
        int size = p.size();
        for(int j=0;j<size;j++){
            m1[i[j]] = j;
        }
        
        return builder(p, i, size, 0, size, 0, size);
    }
};      