class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
        long long dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(vector<int>& pri : prices)
        {
            dp[pri[0]][pri[1]] = pri[2];
        }

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                for(int k = 1; k < i; ++k)
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                for(int k = 1; k < j; ++k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
        return dp[m][n];
    }
};