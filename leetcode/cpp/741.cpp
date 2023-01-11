// 线性DP

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int dp[2 * n - 1][n][n];
        memset(dp, 0xbf, sizeof(dp));
        dp[0][0][0] = grid[0][0];

        for(int i = 1; i < 2 * n - 1; ++i)
        {
            for(int j = max(0, i + 1 - n); j <= min(n - 1, i); ++j)
            {
                if(grid[j][i - j] == -1)
                    continue;
                for(int k = j; k <= min(n - 1, i); ++k)
                {
                    if(grid[k][i - k] == -1)
                        continue;

                    int cur = dp[i - 1][j][k];
                    if(j)
                        cur = max(cur, dp[i - 1][j - 1][k]);
                    if(k)
                        cur = max(cur, dp[i - 1][j][k - 1]);
                    if(j && k)
                        cur = max(cur, dp[i - 1][j - 1][k - 1]);

                    cur += grid[j][i - j];
                    if(j != k)
                        cur += grid[k][i - k];
                    dp[i][j][k] = cur;
                }
            }
        }


        return max(dp[2 * n - 2][n - 1][n - 1], 0);
    }
};