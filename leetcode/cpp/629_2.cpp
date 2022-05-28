//动态规划
//利用前缀和
//O(nk)
//8ms
const int MOD = 1000000007;

class Solution {
public:
    int kInversePairs(int n, int k) {

        long long dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= min(k, (i - 1) * i / 2); ++j)
            {
                if(j <= ((i - 1) * i / 2 - (i - 1) * i / 4) && j < i)
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                else if(j <= ((i - 1) * i / 2 - (i - 1) * i / 4) && j >= i)
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - i]) % MOD;
                else if(j > ((i - 1) * i / 2 - (i - 1) * i / 4))
                {
                    dp[i][j] = dp[i][(i - 1) * i / 2 - j];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return dp[n][k];      
    }
};