/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return res;
        backtrack(root, sum);
        return res;
    }
    
    void backtrack(TreeNode* root, int sum){
        if (!root) return;
        path.push_back(root->val);
        if (!(sum - root->val) && !root->left && !root->right)
            res.push_back(path);
        backtrack(root->left, sum-root->val);
        backtrack(root->right, sum-root->val);
        path.pop_back();
    }
};
