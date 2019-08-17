// 动态规划
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[0] = 0;
        for (int i=1; i<=num; ++i)
            res[i] = res[i&(i-1)] + 1;
        return res;
    }
};


// 直接做法
class Solution_countBit {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i=0; i<=num; ++i)
            res.push_back(count_1(i));
        return res;
    }
    
    int count_1(int val) {
        int num = 0;
        while(val) {
            val &= (val-1);
            ++num;
        }
        return num;
    }
};
