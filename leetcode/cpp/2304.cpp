class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        

        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0x3f, sizeof(dp));

        for(int i = 0; i < n; ++i)
            dp[0][i] = grid[0][i];

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int cur = grid[i - 1][j];
                for(int k = 0; k < n; ++k)
                {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + moveCost[cur][k]);
                }
            }
            for(int j = 0; j < n; ++j)
            {
                dp[i][j] += grid[i][j];
            }
        }

        int ans = 0x3f3f3f3f;
        for(int j = 0; j < n; ++j)
            ans = min(ans, dp[m - 1][j]);
        return ans;
    }
};
