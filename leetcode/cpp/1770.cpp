class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        
        int n = nums.size();
        int m = multipliers.size();

        int dp[m + 1][m + 1];
        memset(dp, 0xc0, sizeof(dp));
        dp[0][0] = 0;

        for(int k = 1; k <= m; ++k)
        {
            for(int i = 0; i <= k; ++i)
            {
                int j = k - i;
                int ret = INT_MIN;
                if(i)
                    ret = max(dp[i - 1][j] + multipliers[k - 1] * nums[i - 1], ret);
                if(j)
                    ret = max(dp[i][j - 1] + multipliers[k - 1] * nums[n - j], ret);

                dp[i][j] = ret;
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i <= m; ++i)
        {
            ans = max(ans, dp[i][m - i]);
        }

        return ans;
    }
};