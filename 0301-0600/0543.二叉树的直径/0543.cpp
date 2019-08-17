/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归，res=max(res, 左子树最大深度+右子树最大深度+1)
class Solution {
    int res = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return res;
        helper(root);
        return res - 1;  // 因为统计的路径长度是按边数目计算，而不是按节点数目计算，所以减1.
    }
    
    int helper(TreeNode* root){
        if (!root) return 0;
        int maxLeftDepth = helper(root->left);
        int maxRightDepth = helper(root->right);
        res = max(res, maxLeftDepth + maxRightDepth + 1);
        return max(maxLeftDepth, maxRightDepth) + 1;
    }
};
