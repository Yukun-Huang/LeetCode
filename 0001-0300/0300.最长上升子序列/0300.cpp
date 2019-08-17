/*
O(n^2)算法:
  动态规划，令dp[i]表示以nums[i]为上升子序列结尾的最大长度，则转移方程为：dp[i]=max(dp[i], dp[j]+1),
  其中j为[0,i)范围内满足nums[j]<nums[i]的索引。

O(nlogn)算法:

*/

class Solution {
public:
        int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return{};
        vector<int> tail(nums.size(), 0);
        tail[0] = nums[0];
        int end = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > tail[end])
                tail[++end] = nums[i];
            else {
                int l = 0, r = end, mid;
                while (l <= r) {
                    mid = (l + r) >> 1;
                    if (tail[mid] > nums[i]&&(mid==0 || (mid>0&&tail[mid-1]<nums[i]) ) )
                        tail[mid] = nums[i];
                    else if (tail[mid] <= nums[i] ) l = mid+1;
                    else r = mid-1;
                }
            }
        }
        return end + 1;
    }
    
    int lengthOfLIS_n2(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> dp(n, 1);
        for (int i=1; i<n; ++i){
            for (int j=0; j<i; ++j){
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        for (auto item : dp)
            res = max(res, item);
        return res;
    }
};
