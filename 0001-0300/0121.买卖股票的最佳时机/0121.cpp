class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0, maxP = 0;
        for (int i=n-2; i>=0; --i){
            maxP = max(maxP, prices[i+1]);
            res = max(res, maxP - prices[i]);
        }
        return res;
    }
};