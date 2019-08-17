/*
设输入队列为 A ，输出队列为 B ，从 A 里挑身高最高的人 x 出来，插入到 B.
因为 B 中每个人的身高都比 x 要高，因此 x 插入的位置，就是看 x 前面应该有多少人就行了。
比如 x 前面有 5 个人，那 x 就插入到队列 B 的第 5 个位置。
*/

bool cmp(const vector<int>& a, const vector<int>& b){
    if (a[0] != b[0])
        return a[0] > b[0];
    else
        return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        int k;
        for (int i=0; i<people.size(); ++i){
            k = people[i][1];
            res.insert(res.begin()+k, people[i]);
        }
        return res;
    }
};
