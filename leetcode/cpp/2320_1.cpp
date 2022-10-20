const int MOD = 1000000007;

class Solution {
public:
    int countHousePlacements(int n) {
        
        long long dp[n][2];
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = dp[i - 1][0] % MOD;
        }

        long long all = (dp[n - 1][0] + dp[n - 1][1]) % MOD;
        return (all * all) % MOD;
    }
};