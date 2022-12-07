class Solution {
public:
    int palindromePartition(string s, int k) {

        int n = s.size();
        int cost[n][n];
        memset(cost, 0, sizeof(cost));

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                if(s[start] != s[end])
                    cost[start][end] = cost[start + 1][end - 1] + 1;
                else
                    cost[start][end] = cost[start + 1][end - 1];
            }
        }

        int dp[n + 1][k + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                for(int l = 1; l <= k; ++l)
                {
                    dp[i][l] = min(dp[i][l], dp[j][l - 1] + cost[j][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};