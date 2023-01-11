class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        int sum = accumulate(rods.begin(), rods.end(), 0);
        int n = rods.size();
        int dp[n + 1][sum + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            memcpy(dp[i + 1], dp[i], sizeof(dp[i + 1]));
            for(int k = 0; k <= sum; ++k)
            {
                if(dp[i][k] < k)
                    continue;

                int k1 = rods[i] + k;
                dp[i + 1][k1] = max(dp[i + 1][k1], dp[i][k] + rods[i]);

                int k2 = abs(rods[i] - k);
                dp[i + 1][k2] = max(dp[i + 1][k2], dp[i][k] + rods[i]);
            }
        }

        return dp[n][0] / 2;
    }
};