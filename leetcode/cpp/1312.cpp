class Solution {
public:
    int minInsertions(string s) {

        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            if(i + 1 < n)
                if(s[i] == s[i + 1])
                    dp[i][i + 1] = 2;
                else
                    dp[i][i + 1] = 1;
        }

        for(int len = 3; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                if(s[start] == s[end])
                    dp[start][end] = dp[start + 1][end - 1] + 2;
                else
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
            }
        }

        return n - dp[0][n - 1];
    }
};