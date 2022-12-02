class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        long long dp[m][n];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> dfs = [&](int x, int y, int pre) -> int {

            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= pre)
                return 0;

            if(dp[x][y] != -1)
                return dp[x][y];

            long long ret = 1;
            ret += dfs(x + 1, y, grid[x][y]);
            ret += dfs(x - 1, y, grid[x][y]);
            ret += dfs(x, y + 1, grid[x][y]);
            ret += dfs(x, y - 1, grid[x][y]);

            ret %= mod;
            return dp[x][y] = ret;

        };

        int ans = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ans += dfs(i, j, -1);
                ans %= mod;
            }
        }

        return ans;
    }
};