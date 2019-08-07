class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = n, left, right;
        for (int i=0; i<2*n-1; ++i){
            if (i % 2)
                left = (i-1)/2, right = (i-1)/2+1;
            else
                left = i/2-1, right = i/2+1;
            while (left >= 0 && right < n){
                if (s[left--] == s[right++])
                    res++;
                else
                    break;
            }
        }
        return res;
    }
};
