//动态规划
//O(n*k*k)
//1768 ms
const int MOD = 1000000007;

class Solution {
public:
    int kInversePairs(int n, int k) {

        long long dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        dp[1][0] = 1;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= min((i - 1) * i / 2, k); ++j)
            {
                for (int l = 0; l <= min(i, k); ++l)
                {
                    if(j + l <= k)
                    {
                        dp[i + 1][j + l] += dp[i][j];
                        dp[i + 1][j + l] %= MOD;
                    }
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[n][k]<<endl;

        return dp[n][k];      
    }
};

