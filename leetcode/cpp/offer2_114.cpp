class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i <= target; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i + nums[j] <= target && dp[i + nums[j]] + dp[i] < INT_MAX)
                    dp[i + nums[j]] += dp[i];
            }
        }

        return dp[target];
    }
};