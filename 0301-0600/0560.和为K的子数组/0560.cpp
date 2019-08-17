/*
O(n)解法
用哈希表快速判断想要的前缀和是否存在
sum[i] - sum[j] == k ?, j < i.
sum[j-1] = sum[i]-k in map?
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, res = 0;
        m[0] = 1;
        for (auto num : nums){
            sum += num;
            if (m.count(sum-k)){
                res += m[sum-k];
            }
            ++m[sum];
        }
        return res;
    }
};
