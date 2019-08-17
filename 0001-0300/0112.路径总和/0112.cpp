/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
注意细节，是从根节点到叶子节点，而不是根节点到任意子节点
*/

class Solution {
public:
    // 迭代
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> s;
        TreeNode* pt;
        int cnt;
        s.push(make_pair(root, sum));
        while (!s.empty()){
            pt = s.top().first;
            cnt = s.top().second;
            s.pop();
            if (!pt) continue;
            if (!(cnt-pt->val) && !(pt->left) && !(pt->right)) // 如果符合
                return true;
            s.push(make_pair(pt->right, cnt-pt->val));
            s.push(make_pair(pt->left, cnt-pt->val));
        }
        return false;
    }
    
    // 递归
    bool hasPathSum_Recursive(TreeNode* root, int sum) {
        if (!root) return false;
        if (!(sum - root->val) && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum-root->val) | hasPathSum(root->right, sum-root->val);
    }
};
