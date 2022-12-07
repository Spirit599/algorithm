class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m][n];
        dp[m - 1][n - 1] = min(dungeon[m - 1][n - 1], 0);

        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(i == m - 1 && j == n - 1)
                    continue;
                int ret = INT_MIN;
                if(i != m - 1)
                    ret = max(ret, dp[i + 1][j]);
                if(j != n - 1)
                    ret = max(ret, dp[i][j + 1]);

                dp[i][j] = min(ret + dungeon[i][j], 0);
            }
        }

        return 1 - dp[0][0];
    }
};