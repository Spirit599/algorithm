class Solution {
public:
    int splitArray(vector<int>& nums, int m) {

        int nums_size = nums.size();
        int dp[nums_size][m + 1];
        int pre[nums_size];
        pre[0] = nums[0];
        for (int i = 1; i < nums_size; ++i)
            pre[i] = pre[i - 1] + nums[i];

        for (int i = 0; i < nums_size; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                dp[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < nums_size; ++i)
            dp[i][1] = pre[i];

        for (int end = 0; end < nums_size; ++end)
        {
            for (int part = 2; part <= m; ++part)
            {
                for (int split = 0; split <= end ; ++split)
                {
                    /* code */
                    dp[end][part] = min(dp[end][part], max(dp[split][part - 1], pre[end] - pre[split]));
                }
            }
        }

        return dp[nums_size - 1][m];
    }
};