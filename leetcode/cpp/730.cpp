const int MOD = 1e9 + 7;

class Solution {
public:
    int countPalindromicSubsequences(string s) {

        int n = s.size();
        long long dp[n][n][4];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
            dp[i][i][s[i] - 'a'] = 1;

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                for(int k = 0; k < 4; ++k)
                {
                    char c = k + 'a';
                    if(s[start] == c && s[end] == c)
                    {
                        dp[start][end][k] = 2 + dp[start + 1][end - 1][0] + dp[start + 1][end - 1][1] + dp[start + 1][end - 1][2] + dp[start + 1][end - 1][3];
                        dp[start][end][k] %= MOD;
                    }
                    else if(s[start] == c)
                    {
                        dp[start][end][k] = dp[start][end - 1][k];
                    }
                    else if(s[end] == c)
                    {
                        dp[start][end][k] = dp[start + 1][end][k];
                    }
                    else
                    {
                        dp[start][end][k] = dp[start + 1][end - 1][k];
                    }
                }
            }
        }


        int ans = 0;
        for(int i = 0; i < 4; ++i)
            ans = (ans + dp[0][n - 1][i]) % MOD;

        return ans;
    }
};