class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int minn = INT_MAX;
                for(int k = 0; k < n; ++k)
                {
                    if(j != k)
                        minn = min(minn, grid[i - 1][k]);
                }
                grid[i][j] += minn;
            }
        }

        return *min_element(grid[m - 1].begin(), grid[m - 1].end());
    }
};