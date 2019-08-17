/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 类似于中序遍历：right->mid->left，即可把节点值从大到小顺序遍历一遍，一直累加并且更新数值即可。
class Solution {
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        helper(root);
        return root;        
    }
    
    void helper(TreeNode* root){
        if (!root) return;
        helper(root->right);
        sum += root->val;
        root->val = sum;
        helper(root->left);
    }
};
