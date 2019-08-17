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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            TreeNode* pT = q.front().first;
            int nL = q.front().second;
            q.pop();

            if (nL == res.size())
                res.emplace_back(vector<int>());
            res.back().push_back(pT->val);

            if (pT->left != NULL)
                q.push(make_pair(pT->left, nL+1));
            if (pT->right != NULL)
                q.push(make_pair(pT->right, nL+1));
        }
        return res;
    }
};