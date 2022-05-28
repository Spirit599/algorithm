//组合数学 重集的排列 本题是排列
//动态规划

class Solution {
const int kind = 26;
const int MOD = 1000000007;

public:
    long long combine(int m, int n)
    {
        if(m < n)
            return 0;

        int k = 1;
        long long ans = 1;

        while(k <= n)
        {
            ans = (m - k + 1) * ans / k;
            ++k;
        }

        return ans;
    }
    int keyboard(int k, int n) {

        long long dp[n + 1][kind + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= kind; ++i)
        {
            dp[0][i] = 1;            
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= kind ; ++j)
            {
                for (int l = 0; l <= k; ++l)
                {
                    if(i - l >= 0)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - l][j - 1] * combine(i, l)) % MOD;
                    }
                }
            }
        }

        return dp[n][kind];
    }
};
