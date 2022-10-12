// 剑指 Offer II 097. 子序列的数目

class Solution {
public:
    int numDistinct(string s, string t) {

        int m = s.size();
        int n = t.size();
        unsigned long long dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for(int j = 0; j < n; ++j)
        {
            unsigned long long sum = 0;
            for(int i = j; i < m; ++i)
            {
                if(t[j] == s[i])
                {
                    sum += dp[i][j];
                }
                dp[i + 1][j + 1] = sum;
                //printf("%d %d %d\n", i,j,dp[i + 1][j + 1]);
            }
        }
        //printf("------------------------------\n");

        return dp[m][n];
    }
};