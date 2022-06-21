// 515 · 房屋染色

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        
        int n = costs.size();
        int dp[n + 1][3];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            dp[i + 1][0] = costs[i][0] + min(dp[i][1], dp[i][2]);
            dp[i + 1][1] = costs[i][1] + min(dp[i][0], dp[i][2]);
            dp[i + 1][2] = costs[i][2] + min(dp[i][1], dp[i][0]);
            //cout<<dp[i + 1][0]<<" "<<dp[i + 1][1]<<" "<<dp[i + 1][2]<<endl;
        }

        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};