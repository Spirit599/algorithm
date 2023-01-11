class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();
        double preSum[n + 1];
        preSum[0] = 0;
        for(int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + nums[i];

        double dp[n + 1][k + 1];
        // for(int i = 0; i <= n; ++i)
        // {
        //     for(int j = 0; j <= k; ++j)
        //     {
        //         dp[i][j] = -100000000;
        //     }
        // }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 0; i < n; ++i)
        {
            int ith = i + 1;
            for(int j = 1; j <= min(ith, k); ++j)
            {
                for(int l = 0; l < ith; ++l)
                {
                    
                    if(j == 1 && l != 0)
                        continue;

                    double dif = ith - l;
                    dp[ith][j] = max(dp[ith][j], dp[l][j - 1] + (preSum[ith] - preSum[l]) / dif);

                }

            }
        }

        return dp[n][k];
    }
};