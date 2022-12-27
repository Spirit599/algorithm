class Solution {
public:
    int numPermsDISequence(string s) {

        int n = s.size();
        long long dp[n + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;

        int mod = 1e9 + 7;

        for(int i = 0; i < n; ++i)
        {
            int len = i + 2;
            if(s[i] == 'D')
            {
                for(int j = 1; j <= len; ++j)
                {
                    for(int k = 1; k < j; ++k)
                    {
                        dp[len][j] = (dp[len][j] + dp[len - 1][k]) % mod;
                    }
                }
            }
            else
            {
                for(int j = 1; j <= len; ++j)
                {
                    for(int k = j; k <= len - 1; ++k)
                    {
                        dp[len][j] = (dp[len][j] + dp[len - 1][k]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n + 1; ++i)
            ans = (ans + dp[n + 1][i]) % mod;

        return ans;
    }
};