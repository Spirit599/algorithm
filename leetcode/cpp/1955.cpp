class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {

        int mod = 1e9 + 7;
        long long dp[3];
        memset(dp, 0, sizeof(dp));
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == 0)
            {
                dp[0] += (dp[0] + 1);
                dp[0] %= mod;
            }
            else if(nums[i] == 1)
            {
                dp[1] += (dp[1] + dp[0]);
                dp[1] %= mod;
            }
            else if(nums[i] == 2)
            {
                dp[2] += (dp[2] + dp[1]);
                dp[2] %= mod;
            }
        }

        return dp[2];

    }
};