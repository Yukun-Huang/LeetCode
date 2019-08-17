// 思路：分别去掉第一个房屋和最后一个房屋后运行一遍DP，取最好结果
// dp[i] = max(dp[i-1], dp[i-2]+nums[i])

class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size()+1, 0);
        int res1 = 0, res2 = 0;
        // 去掉第一个房屋
        dp[1] = nums[1], dp[2] = max(nums[1], nums[2]);
        for (int i=3; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        res1 = dp[nums.size()-1];
        // 去掉最后一个房屋
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<nums.size()-1; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        res2 = dp[nums.size()-2];
        // 返回
        return max(res1, res2);
    }
};
