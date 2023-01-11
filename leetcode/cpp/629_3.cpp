// 629. K个逆序对数组
// 动态规划
class Solution {
public:
    const int MOD = 1000000007;
    int kInversePairs(int n, int k) {

        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        int pre[n + 1][k + 1];
        memset(pre, 0, sizeof(pre));

        
        for(int j = 0; j <= k; ++j)
            pre[0][j] = 1;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= k; ++j)
            {
                if(j < i)
                    dp[i][j] = pre[i - 1][j];
                else
                    dp[i][j] = (pre[i - 1][j] - pre[i - 1][j - i] + MOD) % MOD;
                if(j != 0)
                    pre[i][j] = (pre[i][j - 1] + dp[i][j]) % MOD;
                else
                    pre[i][j] = dp[i][j];
                //printf("%d %d %d\n", i, j, dp[i][j]);
            }

        }

        return dp[n][k];
    }
};