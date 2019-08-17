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
    // 迭代解法
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *left, *right, *pt;
        q.push(root);
        while (!q.empty()) {
            pt = q.front(), q.pop();
            if (!pt) continue;
            left = pt->left, right = pt->right;
            q.push(left), q.push(right);
            pt->left = right;
            pt->right = left;
        }
        return root;
    }
    
    // 递归解法
    TreeNode* invertTree_recursive(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *left, *right;
        left = invertTree(root->left);
        right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
