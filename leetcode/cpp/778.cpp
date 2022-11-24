class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        bool vis[n][n];


        int high = n * n - 1;
        int low = 0;
        int time;

        function<bool(int, int)> dfs = [&](int i, int j) -> bool {

            if(i >= n || i < 0 || j >= n || j < 0 || vis[i][j] || grid[i][j] > time)
                return false;
            if(i == n - 1 && j == n - 1)
                return true;

            vis[i][j] = true;
            return dfs(i, j + 1) || dfs(i, j - 1) || dfs(i + 1, j) || dfs(i - 1, j);
        };

        while(high != low)
        {
            time = (high + low) >> 1;
            memset(vis, 0, sizeof(vis));
            if(dfs(0, 0))
                high = time;
            else
                low = time + 1;
        }

        return low;
    }
};