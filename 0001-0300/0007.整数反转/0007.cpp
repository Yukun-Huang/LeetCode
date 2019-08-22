#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

class Solution {
public:
    int reverse(int x) {
        int digit = 0;
        long long res = 0;
        while (x){
            digit = x % 10;
            x = x / 10;
            res = res * 10 + digit;
        }
        if (res > INT_MAX || res < INT_MIN)
            res = 0;
        return int(res);
    }
};
