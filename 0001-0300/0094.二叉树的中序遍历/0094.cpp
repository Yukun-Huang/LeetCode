/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// Ī��˹�����ĺ���˼�����ڣ������ǰ�ڵ�������������򽫵�ǰ�ڵ���Ϊ���������ҽڵ�����ӽڵ㣬ͬʱ�����������ڵ���Ϊ��ǰ�ڵ㡣ע����һ����ǰ�ڵ��������Ҫ��ΪNULL�Ա�������ѭ����
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

// �ݹ飬��ǰ�����������=�������������+���ڵ�+�������������
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