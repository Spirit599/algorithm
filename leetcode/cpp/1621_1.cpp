//动态规划


const int MOD = 1000000007;

class Solution {
public:
    int numberOfSets(int n, int k) {

        long long dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[2][1] = 1; //方案数
        // dp[3][1] = 3;
        // dp[3][2] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= min(i - 1, k); ++j)
            {
                //cout<<i<<j<<endl;
                dp[i][j] = (2 * dp[i - 1][j] + dp[i - 1][j - 1] - dp[i - 2][j] + MOD) % MOD;
                //cout<<dp[i][j]<<endl;
            }
        }

        return dp[n][k];

    }
};