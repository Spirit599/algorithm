class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        for(auto& guard : guards)
        {
            grid[guard[0]][guard[1]] = 1;
        }
        for(auto& wall : walls)
        {
            grid[wall[0]][wall[1]] = 2;
        }

        int ans = 0;
        int i = 0;
        int j = 0;
        for(auto& guard : guards)
        {
            i = guard[0];j = guard[1];
            while(i + 1 < m && (grid[i + 1][j] != 1 && grid[i + 1][j] != 2))
            {
                ++i;
                if(grid[i][j] == 0)
                {
                    // printf("%d %d\n", i,j);
                    ++ans;
                    grid[i][j] = 3;
                }
            }
            i = guard[0];j = guard[1];
            while(i - 1 >= 0 && (grid[i - 1][j] != 1 && grid[i - 1][j] != 2))
            {
                --i;
                if(grid[i][j] == 0)
                {
                    // printf("%d %d\n", i,j);
                    ++ans;
                    grid[i][j] = 3;
                }
            }
            i = guard[0];j = guard[1];
            while(j + 1 < n && (grid[i][j + 1] != 1 && grid[i][j + 1] != 2))
            {
                ++j;
                if(grid[i][j] == 0)
                {
                    // printf("%d %d\n", i,j);
                    ++ans;
                    grid[i][j] = 3;
                }
            }
            i = guard[0];j = guard[1];
            while(j - 1 >= 0 && (grid[i][j - 1] != 1 && grid[i][j - 1] != 2))
            {
                --j;
                if(grid[i][j] == 0)
                {
                    // printf("%d %d\n", i,j);
                    ++ans;
                    grid[i][j] = 3;
                }
            }

        }
        return n * m - guards.size() - walls.size() - ans;
    }
};