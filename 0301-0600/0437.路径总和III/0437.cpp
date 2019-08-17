/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 哈希表记录前n项和，DFS+回溯
// 采取了类似于数组的前n项和的思路，比如sum[4] == sum[1]，那么1到4之间的和肯定为0

// 对于树的话，采取DFS加回溯，每次访问到一个节点，把该节点加入到当前的pathSum中
// 然后判断是否存在一个之前的前n项和，其值等于pathSum与sum之差
// 如果有，就说明现在的前n项和，减去之前的前n项和，等于sum，那么也就是说，这两个点之间的路径和，就是sum

// 最后要注意的是，记得回溯，把路径和弹出去

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        unordered_map<int, int> m;
        m[0] = 1;
        return helper(root, sum, m, 0);
    }
    
    int helper(TreeNode* root, int sum, unordered_map<int, int>& m, int pathSum){
        int res = 0;
        if(!root) return 0;
        pathSum += root->val;
        res += m.count(pathSum-sum) ? m[pathSum-sum] : 0;
        if (m.count(pathSum))
            m[pathSum] += 1;
        else m[pathSum] = 1;
        res += helper(root->left, sum, m, pathSum) + helper(root->right, sum, m, pathSum);
        m[pathSum] -= 1;
        return res;
    }
};


// 双重递归
class Solution_slow {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int helper(TreeNode* root, int sum){
        if(!root) return 0;
        return (sum == root->val ? 1 : 0) + helper(root->left, sum-root->val) + helper(root->right, sum-root->val);
    }

};
