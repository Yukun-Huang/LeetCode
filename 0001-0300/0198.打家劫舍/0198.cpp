// DP
// f(i): 前i间房屋能够偷到的最大金额
// A(i): 第i间房屋的金额
// f(i) = max{f(i-2)+A[i], f(i-1)}

class Solution {
public:
    int rob_dp(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for (int i=2; i<=n; ++i)
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        return dp[n];
    }
    
     int rob(vector<int>& nums) 
    {
        int sumOdd = 0;
        int sumEven = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i & 1)
            {
                sumEven += nums[i];
                sumEven = max(sumOdd, sumEven);
            }
            else
            {
                sumOdd += nums[i];
                sumOdd = max(sumOdd, sumEven);
            }
        }
        return max(sumOdd, sumEven);
    }
};