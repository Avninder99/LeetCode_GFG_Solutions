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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q1;
        q1.push(root);
        q1.push(NULL);
        vector<int>lvlHolder;
        unordered_map<int, int>m1;
        int res = 0;
        
        while(q1.size() > 1){
            TreeNode* holder = q1.front();
            q1.pop();
            
            if(holder == NULL){
                q1.push(NULL);
                continue;
            }
            
            lvlHolder.push_back(holder->val);
            
            if(holder->left){
                q1.push(holder->left);
            }
            if(holder->right){
                q1.push(holder->right);
            }
            
            if(q1.front() == NULL){
                res += swapper(lvlHolder, m1);
            }
        }
        return res;
    }
private:
    int swapper(vector<int>&lvl, unordered_map<int, int>&m1){
	    vector<int>temp;
	    for(int i=0;i<lvl.size();i++){
	        m1[lvl[i]] = i;
	        temp.push_back(lvl[i]);
	    }
	    sort(temp.begin(), temp.end());
	    int ans = 0;
	    for(int i=0;i<lvl.size();i++){
	        if(lvl[i] != temp[i]){
	            int cvInd = m1[temp[i]], orgH = lvl[i];
	            lvl[i] = lvl[cvInd];
	            m1[temp[i]] = i;
	            
	            lvl[cvInd] = orgH;
	            m1[orgH] = cvInd;
	            
	            ans++;
	        }
	    }
        m1.clear();
        lvl.clear();
	    return ans;
	}
};