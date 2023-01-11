class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        int groupSize = group.size();
        int dp[groupSize + 1][n + 1][minProfit + 1]; // 前k个大于等于profit的方案数
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i <= n; i++) 
            dp[0][i][0] = 1;
        const int MOD = 1e9 + 7;

        
        for(int i = 0; i < groupSize; ++i)
        {
            int jobPro = profit[i];
            int needPer = group[i];
            for(int j = 0; j <= n; ++j)
            {
                for(int k = 0; k <= minProfit; ++k)
                {
                    dp[i + 1][j][k] = dp[i][j][k];
                    if(j >= needPer)
                    {
                        dp[i + 1][j][k] += dp[i][j - needPer][max(k - jobPro, 0)];
                        dp[i + 1][j][k] %= MOD;
                    }
                }
            }
        }

        return dp[groupSize][n][minProfit];

    }
};