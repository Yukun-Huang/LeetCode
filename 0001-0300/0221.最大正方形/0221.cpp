// dp(i, j) = min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nR = matrix.size();
        if (!nR) return 0;
        int nC = matrix[0].size();
        int res = 0;
        vector<int> dp(nC, 0);
        vector<int> odp(nC, 0);
        for (int c=0; c<nC; ++c){
            dp[c] = matrix[0][c] == '1'? 1 : 0;
            res = max(dp[c], res);
        }
        for (int r=1; r<nR; ++r) {
            odp.assign(dp.begin(), dp.end());
            dp[0] = matrix[r][0] == '1'? 1 : 0;
            res = max(dp[0], res);
            for (int c=1; c<nC; ++c){
                if (matrix[r][c] == '1'){
                    dp[c] = min(dp[c-1], min(odp[c-1], odp[c])) + 1;
                }
                else
                    dp[c] = 0;
                res = max(dp[c], res);
            }
        }
        return res * res;
    }
    
    int maximalSquare_dp(vector<vector<char>>& matrix) {
        int nR = matrix.size();
        if (!nR) return 0;
        int nC = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(nR, vector<int>(nC, 0));
        for (int r=0; r<nR; ++r)
            for (int c=0; c<nC; ++c){
                if (!r || !c){
                    dp[r][c] = matrix[r][c] == '1' ? 1 : 0;
                }
                else if (matrix[r][c] == '1'){
                    dp[r][c] = min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1])) + 1;
                }
                res = max(dp[r][c], res);
            }
        return res * res;
    }
};
