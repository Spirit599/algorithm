// 695.岛屿的最大面积

class Solution {
public:
    int m;
    int n;
    int ans = 0;
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            return 0;
        }
        grid[i][j] = 0;

        int ret = 1;

        ret += dfs(i + 1, j, grid);
        ret += dfs(i - 1, j, grid);
        ret += dfs(i, j + 1, grid);
        ret += dfs(i, j - 1, grid);

        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};