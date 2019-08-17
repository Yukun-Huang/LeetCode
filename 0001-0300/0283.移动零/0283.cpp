class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i=0; i<nums.size(); ++i){
            if (nums[i])
                swap(nums, i, cnt++);
        }
    }
};
