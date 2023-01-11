class Solution {
public:
    const int MOD = 1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        int dp[n + 1][3];
        memset(dp, 0, sizeof(dp));

        dp[1][0] = 1;
        if(1 + delay <= n)
            dp[1 + delay][1] = 1;
        if(1 + forget <= n)
            dp[1 + forget][2] = 1;

        for(int i = 2; i <= n; ++i)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;

            dp[i][0] = (dp[i][0] - dp[i][2] + MOD) % MOD;
            dp[i][1] = (dp[i][1] - dp[i][2] + MOD) % MOD;

            dp[i][0] = (dp[i][0] + dp[i][1]) % MOD;

            if(i + delay <= n)
                dp[i + delay][1] = (dp[i + delay][1] + dp[i][1]) % MOD;
            if(i + forget <= n)
                dp[i + forget][2] = (dp[i + forget][2] + dp[i][1]) % MOD;

            //printf("%d %d %d\n", dp[i][0],dp[i][1],dp[i][2]);

        }

        return dp[n][0];
    }
};