// 二分查找左右边界

class Solution {
public:
    
    bool cmp_lb(const int& m, const int& m_next, const int& t)
    {
        if (m >= t)
            return false;
        if (m_next < t)
            return true;
        return true;  // you can return whatever here, it means target not exist.
        //assert(0);
    }
    
    bool cmp_rb(const int& m, const int& m_next, const int& t)
    {
        if (m > t)
            return false;
        if (m_next <= t)
            return true;
        return true;  // you can return whatever here, it means target not exist.
        //assert(0);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // init
        vector<int> ans = {-1, -1};
        int n = nums.size();
        if (!n) return ans;  // empty vector case
        nums.push_back(max(nums[n-1]+1, target+1)); // lazy trick
        // find left bound
        int l = 0, r = n-1;
        while(l <= r){
            int m = (l + r) / 2;
            if (nums[m] < target && nums[m+1] == target){
                ans[0] = m + 1;
                break;
            }
            if (cmp_lb(nums[m], nums[m+1], target))
                l = m + 1;
            else
                r = m - 1;
        }
        if (nums[0] == target)
            ans[0] = 0;
        // find right bound
        l = 0; r = n-1;
        while(l <= r){
            int m = (l + r) / 2;
            if (nums[m] == target && nums[m+1] > target){
                ans[1] = m;
                break;
            }
            if (cmp_rb(nums[m], nums[m+1], target))
                l = m + 1;
            else
                r = m - 1;
        }
        // finish
        return ans;
    }
};
