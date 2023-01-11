// 463. 岛屿的周长

class Solution {
public:
    int m;
    int n;
    int ans = 0;
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            ++ans;
            return ;
        }
        if(grid[i][j] == 2)
            return ;
        grid[i][j] = 2;
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
    int islandPerimeter(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    return ans;
                }
            }
        }

        return -1;
    }
};