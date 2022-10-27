class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        if((m + n) / 2 == 0 || grid[m - 1][n - 1] == '(')
            return false;
        bool ans = false;
        bool vis[m][n][m + n];
        memset(vis, 0, sizeof(vis));

        function<void(int, int, int)> dfs = [&](int i, int j, int diff) -> void {

            //printf("%d %d %d\n", i,j,diff);
            if(i >= m || j >= n || ans)
                return ;

            if(vis[i][j][diff])
                return ;
            vis[i][j][diff] = true;

            if(grid[i][j] == '(')
                ++diff;
            else
                --diff;
            int steps = (m - 1) - i + (n - 1) - j;
            if(diff < 0 || diff > steps)
                return ;
            if(i == m - 1 && j == n - 1 && diff == 0)
            {
                ans = true;
                return;
            }

            dfs(i + 1, j, diff);
            dfs(i, j + 1, diff);
        };
        dfs(0, 0, 0);

        return ans;
    }
};