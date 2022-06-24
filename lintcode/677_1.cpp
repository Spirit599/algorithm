// 677 · 大岛的数量

class Solution {
public:
    /**
     * @param grid: a 2d boolean array
     * @param k: an integer
     * @return: the number of Islands
     */
    int m = 0;
    int n = 0;
    int numsofIsland(vector<vector<bool>> &grid, int k) {
        
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        int ans = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int num = dfs(grid, i, j, visit);
                //cout<<num<<endl;
                if(num >= k)
                    ++ans;
            }
        }

        return ans;
    }

    int dfs(vector<vector<bool>> &grid, int cur_i, int cur_j, vector<vector<bool>>& visit)
    {
        if(cur_i < 0 || cur_i >= m || cur_j < 0 || cur_j >= n || grid[cur_i][cur_j] == false || visit[cur_i][cur_j] == true)
            return 0;

        visit[cur_i][cur_j] = true;
        return dfs(grid, cur_i + 1, cur_j, visit) + 
                dfs(grid, cur_i - 1, cur_j, visit) + 
                dfs(grid, cur_i, cur_j + 1, visit) + 
                dfs(grid, cur_i, cur_j - 1, visit) + 1;
    }
};