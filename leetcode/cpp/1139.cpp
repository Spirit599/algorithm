class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int row[m][n + 1];
        int col[m + 1][n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        int maxLen = min(m, n);
        for(int len = maxLen; len > 0; --len)
        {
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(grid[i][j] == 0)
                        continue;
                    if(i + len - 1 >= m || j + len - 1 >= n)
                        continue;

                    int k = i + len - 1;
                    int l = j + len - 1;
                    if(row[i][l + 1] - row[i][j] == len &&
                       row[k][l + 1] - row[k][j] == len &&
                       col[k + 1][j] - col[i][j] == len &&
                       col[k + 1][l] - col[i][l] == len)
                        return len * len;
                }
            }
        }

        return 0;
    }
};