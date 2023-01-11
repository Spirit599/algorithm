// 329. 矩阵中的最长递增路径
// 记忆化dfs

class Solution {
public:
    int m;
    int n;
    int dp[205][205];
    int dfs(int i, int j, vector<vector<int>>& matrix, int pre)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= pre)
        {
            return 0;
        }
        if(dp[i][j])
            return dp[i][j];

        int ret = 0;
        ret = max(ret, dfs(i + 1, j, matrix, matrix[i][j]) + 1);
        ret = max(ret, dfs(i - 1, j, matrix, matrix[i][j]) + 1);
        ret = max(ret, dfs(i, j + 1, matrix, matrix[i][j]) + 1);
        ret = max(ret, dfs(i, j - 1, matrix, matrix[i][j]) + 1);

        return dp[i][j] = ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int ret = dfs(i, j, matrix, -1);
                ans = max(ans, ret);
            }
        }

        return ans;
    }
};