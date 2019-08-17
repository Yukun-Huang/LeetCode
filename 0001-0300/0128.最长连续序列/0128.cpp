// 1.����������hashed set��
// 2.����num�����num-1��set���continue������
//     current_num = num
//     while(current_num in set) res++, current_num++
// ʱ�临�Ӷ�O(n+n),��O(n).

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