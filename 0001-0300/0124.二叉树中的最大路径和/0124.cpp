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
public:
    int res;
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        res = INT_MIN;
        _maxPathSum(root);
        return res;
    }
    
    int _maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int res_left = _maxPathSum(root->left);
        int res_right = _maxPathSum(root->right);
        int ret = max(root->val, max(res_left+root->val, res_right+root->val));
        int max_val = max(ret, res_left+res_right+root->val);
        if (max_val > res)
            res = max_val;
        return ret;
    }
    
    
};