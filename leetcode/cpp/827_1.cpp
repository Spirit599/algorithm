// 827. 最大人工岛

class Solution {
public:
    unordered_map<int, int> area;
    int m;
    int n;
    unordered_set<int> visited;

    int dfs(int i, int j, vector<vector<int>>& grid, int index)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || grid[i][j] == index)
        {
            return 0;
        }

        grid[i][j] = index;

        int ret = 1;

        ret += dfs(i + 1, j, grid, index);
        ret += dfs(i - 1, j, grid, index);
        ret += dfs(i, j + 1, grid, index);
        ret += dfs(i, j - 1, grid, index);

        return ret;
    }

    int check(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited.count(grid[i][j]))
            return 0;

        visited.insert(grid[i][j]);
        return area[grid[i][j]];
    }

    int afterFillArea(int i, int j, vector<vector<int>>& grid)
    {
        int area = 1;
        visited.clear();
        area += check(i + 1, j, grid);
        area += check(i - 1, j, grid);
        area += check(i, j + 1, grid);
        area += check(i, j - 1, grid);

        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int index = 2;


        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int ret = dfs(i, j, grid, index);
                    area[index] = ret;
                    ++index;
                }
            }
        }

        int ans = 0;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                {
                    ans = max(ans, afterFillArea(i, j, grid));
                }
            }
        }

        if(ans != 0)
            return ans;
        else
            return m * n;
    }
};