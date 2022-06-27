// 1208 · 目标和

class Solution {
public:
    /**
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    int findTargetSumWays(vector<int> &nums, int s) {

        if(s >= 1000 || s <= -1000)
            return 0;
        
        int n = nums.size();
        int dp[n + 1][2001];
        memset(dp, 0, sizeof(dp));
        dp[0][1000] = 1;

        for(int i = 0; i < n; ++i)
        {
            for(int j = -1000; j <= 1000; ++j)
            {
                dp[i + 1][j + 1000] += dp[i][j - nums[i] + 1000];
                dp[i + 1][j + 1000] += dp[i][j + nums[i] + 1000];
                if(dp[i + 1][j + 1000] != 0)
                    cout<<i<<" "<<j + 1000<<" "<<dp[i + 1][j + 1000]<<endl;
            }
        }

        return dp[n][s + 1000];
    }
};