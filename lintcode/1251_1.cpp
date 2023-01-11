// 1251 · 拆分子数组

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        
        int n = nums.size();
        long long dp[n + 1][m + 1];
        //memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i <= n; ++i)
        {
        	for(int j = 0; j <= min(i, m); ++j)
        	{
        		dp[i][j] = 0x7fffffff;
        	}
        }

        long long pre[n + 1];
        pre[0] = 0;
        for(int i = 0; i < n; ++i)
        {
        	pre[i + 1] = pre[i] + nums[i];
        }

        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i)
        {
        	for(int j = 1; j <= min(i, m); ++j)
        	{
        		for(int k = 0; k < i; ++k)
        		{
        			dp[i][j] = min(dp[i][j] ,max(dp[k][j - 1], pre[i] - pre[k]));;
        		}
        	}
        }

        return dp[n][m];
    }
};