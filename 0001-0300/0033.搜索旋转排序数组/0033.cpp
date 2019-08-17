// 方法：改进的二分搜索
// 把数组nums分为左右两部分的纯升序子数组。
// 定义bool类型的pos_target, pos_middle，分别用来记录target值和middle值的位置，false代表在左半部分，true代表在右半部分。
// 根据pos_target和pos_middle的信息，我们可以判断出可能的解会在左半区间还是右半区间。找到规律后，我们得出下面的结论：
//     如果pos_target == pos_middle，则执行标准二分搜索；否则，执行相反的二分搜索（比如说，本来二分搜索应该选择左半区间的，就改成右半区间）。


class Solution {

public:
    int lv, rv;
    bool pos_target;
    bool pos_middle;
    
    bool cmp(const int& m, const int& t)
    {
        pos_middle = m < lv;
        if (!(pos_middle ^ pos_target)) // 同或
            return t > m;
        else
            return !(t > m);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n)
            return -1;
        lv = *nums.begin(), rv = *nums.rbegin();
        pos_target = target < lv;
        
        int l = 0, r = n-1;
        while(l <= r){
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (cmp(nums[m], target))
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};


