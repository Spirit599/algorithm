class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {

        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();
        bool vis[m][n];
        

        function<void(int, int, int)> dfs = [&](int i, int j, int score) {

            
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j])
                return;
            vis[i][j] = true;
            score += grid[i][j];
            ans = max(ans, score);
            dfs(i + 1, j, score);
            dfs(i - 1, j, score);
            dfs(i, j + 1, score);
            dfs(i, j - 1, score);
            vis[i][j] = false;
        };

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                memset(vis, 0, sizeof(vis));
                dfs(i, j, 0);
            }
        }
        return ans;
    }
};