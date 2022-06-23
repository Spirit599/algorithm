// 1827 · 停在原地的方案数2

class Solution {
public:
    /**
     * @param steps: steps you can move
     * @param arrLen: the length of the array
     * @return: Number of Ways to Stay in the Same Place After Some Steps
     */
    int numWays(int steps, int arrLen) {
        
        int n = min(steps, arrLen);
        long long dp[steps + 1][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        const int MOD = 1000000007;

        for(int i = 1; i <= steps; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if(j > 0)
                    dp[i][j] += dp[i - 1][j - 1];
                if(j < n - 1)
                    dp[i][j] += dp[i - 1][j + 1];

                dp[i][j] %= MOD;
            }  
        }

        return dp[steps][0];
    }
};