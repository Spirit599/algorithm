class Solution {
public:
    int strangePrinter(string s) {

        int n = s.size();
        int dp[n][n];
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                for(int split = start; split < end; ++split)
                {
                    dp[start][end] = min(dp[start][end], dp[start][split] + dp[split + 1][end]);
                }
                if(s[start] == s[end])
                    --dp[start][end];
            }
        }

        return dp[0][n - 1];
    }
};