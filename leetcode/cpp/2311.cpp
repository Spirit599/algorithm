class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int n = s.size();
        int dp[n][n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = s[0] - '0';

        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = min(dp[i - 1][0], s[i] - '0');
            for(int j = 1; j <= n; ++j)
            {
                dp[i][j] = min({k + 1, dp[i - 1][j], 2 * dp[i - 1][j - 1] + s[i] - '0'});
            }
        }
        for(int i = 0; i <= n; ++i)
        {
            if(dp[n - 1][i] > k)
            {
                printf("%d\n", dp[n - 1][i]);
                return i;
            }
        }
        return 0;
    }
};