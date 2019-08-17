// 动态规划
// dp_max[i]：以nums[i]结尾的子序列的最大值
// dp_min[i]：以nums[i]结尾的子序列的最小值

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, dp_max = 1, dp_min = 1, tmp;
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] > 0){
                dp_max = max(nums[i], dp_max*nums[i]);
                dp_min = min(nums[i], dp_min*nums[i]);
            }
            else if (nums[i] < 0){
                tmp = dp_max;   // 注意不要忘记这一步!!!!!
                dp_max = max(nums[i], dp_min*nums[i]);
                dp_min = min(nums[i], tmp*nums[i]);
            }
            else{
                dp_max = 0;
                dp_min = 0;
            }
            res = max(dp_max, res);
        }
        return res;
    }
};
