// 暴力解法，即递归回溯，时间复杂度O(n!)

/*
动态规划：
    设dp[i][j]为[i,j]区间所能获得的最大硬币数。
思路的关键点在于，对于区间[i,j]，若我们最后戳破气球k (i<=k<=j)，那么左区间[i,k]和右区间[k,j]其实是没有关联的两个子问题。则我们可以得到转移方程：
    for k in [i, k]:
        delta = nums[i-1] * nums[k] * nums[j+1]
        dp[i][j] = max(dp[i][j], dp[i,k-1] + dp[k+1,j] + delta)
    这里可以递归实现，然后用memo记录中间值就不会超时了。

自底而上动态规划：
    用长度作为第一层循环即可，代码如下。
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // 加入哨兵
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // dp[i][j]表示[i,j]范围内最大硬币数
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // 这里不能按行打表，只能按长度打表, dp[i][j], j-i >= 2
        for (int len = 2; len < n; ++len) {
            for (int i = 0; i < n - len; ++i) {
                int j = i + len;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};


