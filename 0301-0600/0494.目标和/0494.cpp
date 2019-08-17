/* 动态规划
我们把问题转换一下，设数组总和为sum，正子集的总和为sum_p，负子集的总和为sum_n.
因此有，
    S = sum_p + sum_n
    S - sum_n = sum_p
    S - sum_n + sum_p = 2 * sum_p
    sum_p = (S + sum) / 2
所以我们只需要找到一个子集，使得总和等于sum_p即可。后面可参考Leetcode 416.分割等和子集和0-1背包问题.
DP[i]代表组成数值i有多少种方法，DP[i] = DP[i] + DP[i-num].
注意！当S过大时可能会内存超限，所以应该判断sum是否大于S.
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (S > sum) return 0;
        if ((sum+S) & 1) return 0;
        sum = (sum + S) / 2;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (auto num : nums){
            for (int j=sum; j>=num; --j){
                dp[j] = dp[j] + dp[j-num];
            }
        }
        return dp[sum];
    }
};


// 暴力递归方法，直接使用会超时，采用memo记录中间结果
class Solution_DFS_memo {
public:
    int S;
    vector<vector<int>> memo;
    vector<vector<bool>> exist;
    int findTargetSumWays(vector<int>& nums, int S) {
        this->S = S;
        this->memo = vector<vector<int>>(nums.size()+1, vector<int>(2000+5, 0));  // 正负索引范围，所以是1000*2 = 2000
        this->exist = vector<vector<bool>>(nums.size()+1, vector<bool>(2000+5, false));
        return helper(nums, 0, 0);
    }
    
    int helper(vector<int>& nums, int idx, int sum){
        if (idx == nums.size())
            return sum == S ? 1 : 0;
        if (!exist[idx][sum+1000]){
            int res = helper(nums, idx+1, sum+nums[idx]) + helper(nums, idx+1, sum-nums[idx]);
            memo[idx][sum+1000] = res;
            exist[idx][sum+1000] = true;
            return res;
        }
        else
            return memo[idx][sum+1000];
    }
};
