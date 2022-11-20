class Solution {
public:
    bool checkMagicSquare(int i, int j, vector<vector<int>>& grid)
    {
        int a = 1;
        for(int k = i; k <= i + 2; ++k)
        {
            for(int l = j; l <= j + 2; ++l)
            {
                // printf("k = %d l = %d\n", k, l);
                a *= grid[k][l];
            }
        }
        if(a != 362880)
            return false;

        int row0 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int row1 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int row2 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        if(row0 != row1 || row0 != row2)
            return false;

        int col0 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int col1 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int col2 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        if(col0 != col1 || col0 != col2)
            return false;

        int diagonal1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int diagonal2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
        if(diagonal1 != diagonal2)
            return false;
        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i + 2 < m; ++i)
        {
            for(int j = 0; j + 2 < n; ++j)
            {
                // printf("%d %d\n", i, j);
                if(checkMagicSquare(i, j, grid))
                    ++ans;
            }
        }

        return ans;
    }
};