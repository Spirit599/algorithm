//309. 最佳买卖股票时机含冷冻期

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int dp[n][3];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = -prices[0];
        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};