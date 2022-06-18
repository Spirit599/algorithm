//576. 出界的路径数
//动态规划
class Solution {
public:
    const int MOD = 1000000007;
    int dp[55][55][55];


    int dfs(int m, int n, int curRow, int curColumn, int curMove)
    {
        //printf("%d %d %d %d %d\n", m,n,curRow,curColumn,curMove);
        if(curRow < 0 || curRow >= m || curColumn < 0 || curColumn >= n)
            return 1;

        if(curMove == 0)
            return 0;

        if(dp[curRow][curColumn][curMove] != -1)
            return dp[curRow][curColumn][curMove];

        return dp[curRow][curColumn][curMove] = 
                (0ll + dfs(m, n, curRow + 1, curColumn, curMove - 1) + 
                dfs(m, n, curRow - 1, curColumn, curMove - 1) + 
                dfs(m, n, curRow, curColumn + 1, curMove - 1) + 
                dfs(m, n, curRow, curColumn - 1, curMove - 1)) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        memset(dp, -1, sizeof(dp));
        return dfs(m, n, startRow, startColumn, maxMove);

    }
};