// 思路
// 自顶而下的动态规划，找到转移方程就好办了，用递归实现很容易
// 引入哈希表作为memo避免重复运算

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
    unordered_map<TreeNode*, int> m;
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (m.count(root)) return m[root];
        int res = 0;
        if (!root->left && !root->right) res = root->val;
        else if (!root->left && root->right)
            res = max(rob(root->right), root->val+rob(root->right->left)+rob(root->right->right));
        else if (root->left && !root->right)
            res = max(rob(root->left), root->val+rob(root->left->left)+rob(root->left->right));
        else
            res = max(rob(root->left) + rob(root->right),
                      rob(root->left->left)  + rob(root->left->right) +
                      rob(root->right->left) + rob(root->right->right) +
                      root->val
                     );
        m[root] = res;
        return res;
    }
};
