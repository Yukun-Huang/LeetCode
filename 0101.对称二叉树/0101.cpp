/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution_Iteration {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> q;
		q.push(root->left);
		q.push(root->right);
		while (!q.empty()) {
			TreeNode* p1 = q.front();
			q.pop();
			TreeNode* p2 = q.front();
			q.pop();

			if (p1 == NULL && p2 == NULL) continue;
			else if (p1 == NULL || p2 == NULL) return false;
			if (p1->val != p2->val) return false;

			q.push(p1->left);
			q.push(p2->right);
			q.push(p1->right);
			q.push(p2->left);
		}
		return true;
	}
};


class Solution_Recursion {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode* pLeft, TreeNode* pRight) {
		if (pLeft == NULL && pRight == NULL)
			return true;
		else if (pLeft == NULL || pRight == NULL)
			return false;

		if (pLeft->val == pRight->val && isMirror(pLeft->left, pRight->right) &&
			isMirror(pLeft->right, pRight->left))
			return true;
		else
			return false;
	}
};


