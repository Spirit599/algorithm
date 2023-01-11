class Solution {
public:
    int checkRecord(int n) {

        long long dp[n + 1][3][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        const int MOD = 1e9 + 7;

        for(int i = 1; i <= n; ++i)
        {
            dp[i][0][0] = (dp[i][0][0] + dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][2][0]) % MOD; //P
            dp[i][0][1] = (dp[i][0][1] + dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][2][1] + dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][2][0]) % MOD; //P A

            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][0]) % MOD; // L
            dp[i][1][1] = (dp[i][1][1] + dp[i - 1][0][1]) % MOD; // L

            dp[i][2][0] = (dp[i][2][0] + dp[i - 1][1][0]) % MOD; // L
            dp[i][2][1] = (dp[i][2][1] + dp[i - 1][1][1]) % MOD; // L
        }

        int ans = 0;
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                ans = (ans + dp[n][i][j]) % MOD;
                // printf("%d %d %d\n", i,j,dp[n][i][j]);
            }
        }

        return ans;
    }
};