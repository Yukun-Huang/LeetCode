class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int left = 1, right = 0;
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] != tmp[i]){
                left = i;
                break;
            }
        }
        for (int i=nums.size()-1; i>=0; --i){
            if (nums[i] != tmp[i]){
                right = i;
                break;
            }
        }
        return right - left + 1;
    }
};
