// 剑指 Offer II 112. 最长递增路径

class Solution {
public:
    int vis[205][205];
    int ans = 0;
    int m;
    int n;
    int dfs(int i, int j, vector<vector<int>>& matrix, int pre) {

        if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= pre)
            return 0;


        if(vis[i][j] != -1)
            return vis[i][j];

        // printf("%d %d\n", i,j);

        int ret = 0;
        pre = matrix[i][j];
        ret = max(ret, dfs(i + 1, j, matrix, pre) + 1);
        ret = max(ret, dfs(i - 1, j, matrix, pre) + 1);
        ret = max(ret, dfs(i, j + 1, matrix, pre) + 1);
        ret = max(ret, dfs(i, j - 1, matrix, pre) + 1);

        ans = max(ans, ret);

        return vis[i][j] = ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();
        memset(vis, -1, sizeof(vis));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                dfs(i, j, matrix, INT_MIN);
            }
        }

        return ans;
    }
};