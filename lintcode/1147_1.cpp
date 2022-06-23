// 1147 · 工作安排

class Solution {
public:
    /**
     * @param low: the simple task
     * @param high: the complex task
     * @return: the most value
     */
    int workPlan(vector<int> &low, vector<int> &high) {
        
        int n = low.size();
        int dp[n + 1][3];
        memset(dp, 0, sizeof(dp));
        dp[0][2] = -high[0];

        for(int i = 0; i < n; ++i)
        {
            dp[i + 1][0] = max({dp[i][0], dp[i][1], dp[i][2]}) + low[i];
            dp[i + 1][1] = dp[i][2] + high[i];
            dp[i + 1][2] = max({dp[i][0], dp[i][1], dp[i][2]});
            //cout<<dp[i + 1][0]<<" "<<dp[i + 1][1]<<" "<<dp[i + 1][2]<<endl;
        }

        return max({dp[n][0], dp[n][1], dp[n][2]});
    }
};