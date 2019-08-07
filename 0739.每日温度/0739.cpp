/*
1.首先我们考虑暴力解法，对于每一天的温度都向后扫描找到温度升高的天数，复杂度为O(n^2).
2.考虑两种特殊情况。如果温度是递增的，那么每次只需扫描一次即可找到目标天数；如果温度是递减的，那么每次都需要扫描到结尾。
3.使用递减的单调栈。
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> s;
        for (int i=0; i<T.size(); ++i){
            if (s.empty() || T[i] <= T[s.top()])
                s.push(i);
            else{
                while(!s.empty() && T[i] > T[s.top()]){
                    res[s.top()] = i - s.top();
                    s.pop();    
                }
                s.push(i);
            }
        }
        // while (!s.empty()){
        //     res[s.top()] = 0;
        //     s.pop();
        // }
        return res;
    }
};
