// DP
// f(i) = min(f(i), f(i-j*j)+1)

class Solution {
public:
    int numSquares(int n) {
       while(n%4==0) n/=4;
       if(n%8==7) return 4;
       for(int a=0;a*a<=n;++a)
       {
           int b=sqrt(n-a*a);
           if(a*a+b*b==n) {
               return !!a+!!b;
           }
       } 
       return 3;
    }
    
    int numSquares_dp(int n) {
        vector<int> dp(n+1);
        for (int i=0; i<=n; ++i)
            dp[i] = i;
        for (int i=1; i<=n; ++i){
            for (int j=1; i-j*j>=0; ++j)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        }
        return dp[n];
    }
};
