class Solution {
public:
    int rearrangeSticks(int n, int k) {

        int mod = 1e9 + 7;
        long long dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= k; ++j)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1)) % mod;
            }
        }

        return dp[n][k];
    }
};