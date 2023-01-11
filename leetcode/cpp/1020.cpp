class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int k = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                    ++k;
            }
        }

        function<void(int, int)> dfs = [&](int i, int j) {

            if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
                return ;
            grid[i][j] = 0;
            --k;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        for(int i = 0; i < m; ++i)
        {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for(int j = 0; j < n; ++j)
        {
            dfs(0, j);
            dfs(m - 1, j);
        }

        return k;
    }
};