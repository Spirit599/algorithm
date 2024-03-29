class Solution {
public:
    int countVowelPermutation(int n) {

        long long dp[n + 1][5];
        memset(dp, 0, sizeof(dp));
        const int MOD = 1e9 + 7;
        for(int i = 0; i < 5; ++i)
            dp[1][i] = 1;

        for(int i = 2; i <= n; ++i)
        {
            dp[i][0] = (dp[i][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD; 
            dp[i][1] = (dp[i][1] + dp[i - 1][0] + dp[i - 1][2]) % MOD; 
            dp[i][2] = (dp[i][2] + dp[i - 1][1] + dp[i - 1][3]) % MOD; 
            dp[i][3] = (dp[i][3] + dp[i - 1][2]) % MOD; 
            dp[i][4] = (dp[i][4] + dp[i - 1][2] + dp[i - 1][3]) % MOD; 
        }

        int ans = 0;
        for(int i = 0; i < 5; ++i)
            ans = (ans + dp[n][i]) % MOD;
        return ans;

    }
};