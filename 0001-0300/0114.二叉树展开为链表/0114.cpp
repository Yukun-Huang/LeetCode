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
    void flatten(TreeNode* root){
        if (root == NULL)
            return;
        if (root->left != NULL){
            TreeNode *pre = root->left;
            while(pre->right != NULL)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->right);
    }
};