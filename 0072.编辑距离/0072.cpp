class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[n+1];
        for (int i=0; i<=n; i++)  // init
            dp[i] = i;
        int old, tmp;  // represent dp[i-1][j-1]
        for (int i=1; i<=m; i++){
            dp[0] = i;
            old = i-1;
            for (int j=1; j<=n; j++){
                tmp = dp[j];
                if (word1[i-1] != word2[j-1])
                    dp[j] = min(min(dp[j], dp[j-1]), old) + 1;
                else
                    dp[j] = old;
                old = tmp;
            }
        }
        return dp[n];
    }
};
