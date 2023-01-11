// 200. 岛屿数量

class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++ans;
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }
};