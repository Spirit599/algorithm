const int MOD = 1000000007;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n][k];
        memset(dp, 0, sizeof(dp));

        dp[0][0][grid[0][0] % k] = 1;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int value = grid[i][j];
                for(int l = 0; l < k; ++l)
                {
                    int& kk = dp[i][j][(l + value) % k];
                    if(i != 0)
                        kk = (kk + dp[i - 1][j][l]) % MOD; 
                    if(j != 0)
                        kk = (kk + dp[i][j - 1][l]) % MOD;
                }

            }
        }

        return dp[m - 1][n - 1][0];
    }
};