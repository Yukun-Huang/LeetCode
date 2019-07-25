// 1.所有数存入hashed set里
// 2.遍历num，如果num-1在set里，则continue，否则：
//     current_num = num
//     while(current_num in set) res++, current_num++
// 时间复杂度O(n+n),即O(n).

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums)
            s.insert(num);
        int res = 0, current_num, cnt;
        for (auto num : nums){
            if (!s.count(num-1)){
                current_num = num, cnt = 0;
                while (s.count(current_num)){
                    cnt++;
                    current_num++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};