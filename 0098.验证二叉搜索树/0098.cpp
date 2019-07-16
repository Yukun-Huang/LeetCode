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
	bool isValidBST(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))  // 若为空节点或叶节点，返回
			return true;
		if (root->left != NULL) {
			if (getMaxVal(root->left) >= root->val)
				return false;
			if (!isValidBST(root->left))
				return false;
		}
		if (root->right != NULL) {
			if (getMinVal(root->right) <= root->val)
				return false;
			if (!isValidBST(root->right))
				return false;
		}
		return true;
	}

	int getMaxVal(TreeNode* pLeft) {
		int maxVal = pLeft->val;
		while (pLeft->right != NULL) {
			pLeft = pLeft->right;
			maxVal = max(maxVal, pLeft->val);
		}
		return maxVal;
	}

	int getMinVal(TreeNode* pRight) {
		int minVal = pRight->val;
		while (pRight->left != NULL) {
			pRight = pRight->left;
			minVal = min(minVal, pRight->val);
		}
		return minVal;
	}
};