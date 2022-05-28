class Solution {
    int n = 0;
    int m = 0; 
    int border_color = 0;
    int pre_color = 0;
    vector<vector<int>> ans;
public:
    void dfs(vector<vector<int>>& grid, int cur_i, int cur_j, vector<vector<bool>>& visit)
    {
        int dires[] = {-1, 0, 1, 0, -1};
        bool border = false;
        //printf("%d %d %d %d\n",cur_i, cur_j ,pre_color,grid[cur_i][cur_j]);
        for (int k = 0; k < 4; ++k)
        {
            int i = cur_i + dires[k];
            int j = cur_j + dires[k + 1];
            if(i >= 0 && i < n && j >= 0 && j < m && !visit[i][j])
            {
                if(grid[i][j] == pre_color)
                {
                    visit[i][j] = true;
                    dfs(grid, i, j, visit);
                }
                else
                {
                    border = true;
                }

            }
        }
        if(border || cur_i == 0 || cur_i == n - 1 || cur_j == 0 || cur_j == m - 1)
        {

            ans[cur_i][cur_j] = border_color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        n = grid.size();
        m = grid[0].size();
        ans = grid;
        pre_color = grid[row][col];
        border_color = color;
        vector<vector<bool>> visit(n, vector<bool>(m));

        //grid[row][col] = color;
        dfs(grid, row, col, visit);

        return ans;
    }
};