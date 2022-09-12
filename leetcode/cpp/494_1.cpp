// 494. 目标和

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int dp[n + 1][2001];
        memset(dp, 0, sizeof(dp));
        dp[0][1000] = 1;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= 2000; ++j)
            {
                int k = nums[i];
                if(j - k <= 2000 && j - k >= 0)
                    dp[i + 1][j] += dp[i][j - k];
                if(j + k <= 2000 && j + k >= 0)
                    dp[i + 1][j] += dp[i][j + k];
            }
        }

        return dp[n][target + 1000];
    }
};