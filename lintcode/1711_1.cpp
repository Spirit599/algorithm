// 1711 · 下降路径最小和

class Solution {
public:
    /**
     * @param a: the given array
     * @return: the minimum sum of a falling path
     */
    int minFallingPathSum(vector<vector<int>> &a) {
        
        int m = a.size();
        int n = a[0].size();

        int dp[m][n];
        memset(dp, 0x3f, sizeof(dp));

        for(int j = 0; j < n; ++j)
            dp[0][j] = a[0][j];

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
                if(j != 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
                if(j != n - 1)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
            }
        }

        int ans = 0x7fffffff;
        for(int j = 0; j < n; ++j)
            ans = min(ans, dp[m - 1][j]);

        return ans;
    }
};