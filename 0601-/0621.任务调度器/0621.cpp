/*
1.计算每个任务出现的次数
2.找出出现次数最多的任务，假设出现次数为 x
3.计算至少需要的时间 (x - 1) * (n + 1)，记为 min_time
4.计算出现次数为 x 的任务总数 count，计算最终结果为 min_time + count
5.特殊情况时，计算出来的结果可能小于数组长度，这时应该返回数组长度（对应于所有空缺都能填上，无待命状态）
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxCnt = 0, maxNum = 0;
        char maxChar = 0;
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (char c : tasks){
            freq[c-'A']++;
            if (freq[c-'A'] > maxCnt){
                maxCnt = freq[c-'A'];
                maxChar = c;
            }
        }
        for (int i=0; i<26; ++i){
            if (freq[i] == maxCnt)
                maxNum++;
        }
        int minTime = (maxCnt-1) * (n+1) + maxNum;
        int minLimitTime = tasks.size();
        return max(minLimitTime, minTime);
    }
};
