class Solution {
public:
    int count_1(int val) {
        int num = 0;
        while(val) {
            val &= (val -1);
            ++num;
        }
        return num;
    }
    
    int hammingDistance(int x, int y) {
        return count_1(x ^ y);
    }
};
