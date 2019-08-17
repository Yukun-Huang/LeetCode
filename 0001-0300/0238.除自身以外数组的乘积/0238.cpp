/*
方法1, 空间复杂度为O(n):
  由于不能使用除法，所以不能直接采用前缀积的方法了。但是可以做一些简单的修改：
  a.计算前缀积数组pre和后缀积数组pos
  b. res[i] = pre[i-1] * pos[i+1], 注意边界情况
  
方法2, 空间复杂度为O(1)，不包括输出数组:
  只要对方法1进行优化即可。因为输出数组不被视为额外空间，所以直接把前缀积数组作为输出数组，在计算后缀积时更新。
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        // phase 1: 计算前缀积
        res[0] = nums[0];
        for (int i=1; i<n; ++i){
            res[i] = res[i-1] * nums[i];
        }
        // phase 2: 更新结果
        int pos = nums[n-1];
        res[n-1] = res[n-2];
        for (int i=n-2; i>=1; --i){
            res[i] = res[i-1] * pos;
            pos *= nums[i];
        }
        res[0] = pos;
        return res;
    }
    
    vector<int> productExceptSelf_method1(vector<int>& nums) {
        int n = nums.size();
        // phase 1
        vector<int> res(n, 0), pre(n, 1), pos(n, 1);
        pre[0] = nums[0], pos[n-1] = nums[n-1];
        for (int i=1; i<n; ++i){
            pre[i] = pre[i-1] * nums[i];
        }
        for (int i=n-2; i>=0; --i){
            pos[i] = pos[i+1] * nums[i];
        }
        // phase 2
        res[0] = pos[1], res[n-1] = pre[n-2];
        for (int i=1; i<n-1; ++i)
            res[i] = pre[i-1] * pos[i+1];
        return res;
    }
};
