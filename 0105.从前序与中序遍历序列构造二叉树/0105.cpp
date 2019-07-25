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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(0, 0, preorder.size(), preorder, inorder);
    }
    
    TreeNode* _buildTree(int startPreIdx, int startInIdx, int len, vector<int>& preorder, vector<int>& inorder){
        if (len == 0) return NULL;
        int rootVal = preorder[startPreIdx];
        TreeNode* root = new TreeNode(rootVal);
        if (len == 1) return root;
        // find root in inorder
        int rootInIdx = -1;
        int leftLen = -1;
        for (int i=startInIdx; i<startInIdx+len; ++i){
            leftLen++;
            if (inorder[i] == rootVal){
                rootInIdx = i;
                break;
            }
        }
        root->left = _buildTree(startPreIdx+1, startInIdx, leftLen, preorder, inorder);
        root->right = _buildTree(startPreIdx+1+leftLen, rootInIdx+1, len-leftLen-1, preorder, inorder);
        return root;
    }
};