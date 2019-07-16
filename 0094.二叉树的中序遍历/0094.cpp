/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// 莫里斯遍历的核心思想在于，如果当前节点存在左子树，则将当前节点作为左子树最右节点的右子节点，同时以左子树根节点作为当前节点。注意上一个当前节点的左子树要置为NULL以避免无限循环。
class Solution_MorrisTraversal {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL) return res;
		TreeNode* curr = root;
		TreeNode* pre;
		while (curr != NULL) {
			if (curr->left == NULL) {
				res.push_back(curr->val);
				curr = curr->right;             // move to next right node
			}
			else {                            // has a left subtree
				pre = curr->left;
				while (pre->right != NULL) {    // find rightmost
					pre = pre->right;
				}
				pre->right = curr;              // put cur after the pre node
				TreeNode* temp = curr;          // store cur node
				curr = curr->left;              // move cur to the top of the new tree
				temp->left = NULL;              // original cur left be null, avoid infinite loops
			}
		}
		return res;
	}
};

// 递归，当前树的中序遍历=左子树中序遍历+根节点+右子树中序遍历
class Solution_Recursive {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL)
			return vector<int>();
		vector<int> vLeft = inorderTraversal(root->left);
		vector<int> vRight = inorderTraversal(root->right);
		vLeft.push_back(root->val);
		vLeft.insert(vLeft.end(), vRight.begin(), vRight.end());
		return vLeft;
	}
};