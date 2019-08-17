/* 思路-回溯法记路径
1.DFS找到p，记录路径path-p
2.DFS找到q，记录路径path-q
3.扫描path-p和path-q的最近公共祖先
*/

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
    void DFS(TreeNode* root, TreeNode*& p, vector<TreeNode*>& buffer, bool& stop_flag) {
        if ((!root) || stop_flag) return;
        if(!stop_flag) buffer.push_back(root);
        if (root == p){
            stop_flag = true;
            return;
        }
        DFS(root->left, p, buffer, stop_flag);
        DFS(root->right, p, buffer, stop_flag);
        if(!stop_flag) buffer.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // dfs
        vector<TreeNode*> buffer_p, buffer_q;
        bool stop_flag = false;
        DFS(root, p, buffer_p, stop_flag);
        stop_flag = false;
        DFS(root, q, buffer_q, stop_flag);
        // find
        TreeNode* res;
        int len = min(buffer_q.size(), buffer_p.size()), idx = 0;
        while (idx < len && buffer_p[idx] == buffer_q[idx])
            res = buffer_p[idx++];
        return res;
    }
};


//     void DFS(TreeNode* root, TreeNode* p, vector<TreeNode*>& buffer) {
//         stack<pair<TreeNode*, int>> s;
//         s.push(root);
//         while (!s.empty()){
//             TreeNode* tmp = s.top();
//             s.pop();
//             buffer.push(root);

//             if (!tmp) continue;
//             if (tmp == p)
//                 buffer.push_back(tmp), return;
//             s.push(tmp->right), s.push(tmp->left);
//         }
//     }
    
