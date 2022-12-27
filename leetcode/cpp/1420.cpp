class Solution {
public:
    int mod = 1e9 + 7;
    long long quickPow(long long x, int k) {

        long long ans = 1;
        while(k) {

            if(k & 1)
                ans = (ans * x) % mod;
            x = (x * x) % mod;
            k = k >> 1;
        }
        return ans;
    }
    int numOfArrays(int n, int m, int k) {

        long long dp[n + 1][k + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        long long pre[n + 1][k + 1][m + 1];
        memset(pre, 0, sizeof(pre));
        for(int i = 0; i <= m; ++i)
            pre[0][0][i] = 1;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= min(i, k); ++j)
            {
                for(int maxn = 1; maxn <= m; ++maxn)
                {
                    for(int lastIdx = 1; lastIdx <= i; ++lastIdx)
                    {
                        dp[i][j][maxn] += pre[lastIdx - 1][j - 1][maxn - 1] * quickPow(maxn, i - lastIdx);
                        dp[i][j][maxn] %= mod;
                    }
                    // printf("%d %d %d %d \n", i,j,maxn,dp[i][j][maxn]);
                    pre[i][j][maxn] += pre[i][j][maxn - 1] + dp[i][j][maxn];
                    pre[i][j][maxn] %= mod;

                }
            }
        }

        return pre[n][k][m];
    }
};