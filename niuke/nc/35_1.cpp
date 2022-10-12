
class Solution {
  public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        int m = str1.size();
        int n = str2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[i + 1][0] = (i + 1) * dc;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j + 1] = (j + 1) * ic;
        }


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d %d\n", i, j);
                if (str1[i] == str2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else
                    dp[i + 1][j + 1] = min({dp[i][j] + rc, dp[i][j + 1] + dc, dp[i + 1][j] + ic});
            }
        }

        return dp[m][n];
    }
};