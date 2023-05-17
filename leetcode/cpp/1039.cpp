class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        int dp[n][n];
        memset(dp, 0x3f, sizeof(dp));

        for(int i = 0; i + 1 < n; ++i)
        {
            dp[i][i] = 0;
            dp[i][i + 1] = 0;
        }

        for(int len = 3; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                for(int split = start + 1; split <= end - 1; ++split)
                {
                    dp[start][end] = min(dp[start][end], dp[start][split] + dp[split][end] + values[start] * values[end] * values[split]);
                }
            }
        }

        return dp[0][n - 1];
    }
};