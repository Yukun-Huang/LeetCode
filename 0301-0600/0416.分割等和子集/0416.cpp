/*
动态规划
1.先统计数组总和，如果该和为奇数，则不存在可能的分割，返回false；否则，该和除以2，进入下一步
2.原问题可以转换为，如果存在一个子集，使得它的和等于目标和，则说明存在这样的分割。因此，考虑类似背包问题的动态规划：
dp[i][j]表示前i个元素能否构成目标和j,状态转移公式为：
  dp[i][j] = dp[i-1][j] || {dp[i-1][j-nums[j]], j-nums[j]>=0}
注意！在用滚动数组优化空间复杂度时，必须采用从后到前遍历的形式！
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // phase 1
        int sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum & 1) return false;
        sum = sum / 2;
        // phase 2
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i=0; i<nums.size(); ++i){
            if (dp[sum]) return true;
            for (int j=sum; j>=0; --j){
                if (j-nums[i]>=0)
                    dp[j] = dp[j] | dp[j-nums[i]];
                else
                    break;
            }
        }
        return dp[sum];
    }
};
