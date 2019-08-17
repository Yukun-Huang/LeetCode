// 哈希表 + 优先队列

typedef pair<int, int> IIPair;

struct cmp {
    bool operator()(const IIPair &left, const IIPair &right) const
    {
        return left.second > right.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 计算元素频率
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        // 优先队列求tok-K
        priority_queue<IIPair, vector<IIPair>, cmp> q; // 创建一个小顶堆
        for (auto item : mp) {
            if (q.size() < k) {
                q.push(item);
            } else if (item.second > q.top().second) {
                q.pop();
                q.push(item);
            }
        }
        // 返回结果
        vector<int> ret(q.size(), 0);
        while (!q.empty()) {
            ret[q.size()-1] = q.top().first;
            q.pop();
        }
        return ret;
    }
};
