class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT32_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            sum += nums[i];
            if (sum > max_sum)
                max_sum = sum;
            sum = max(0, sum);
        }
        return max_sum;
    }
};
