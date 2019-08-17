class Solution {
public:
    // 巧妙做法
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto num : nums){
            int idx = abs(num) - 1;
            nums[idx] = - abs(nums[idx]);
        }
        vector<int> res;
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
    
    // 用了额外数组记录
    vector<int> findDisappearedNumbers_extraMemory(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(n+1, 0);
        for (auto num : nums){
            record[num] = 1;
        }
        nums.clear();
        for (int i=1; i<=n; ++i){
            if (!record[i])
                nums.push_back(i);
        }
        return nums;
    }
};
