//76 · 最长上升子序列

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        
        int n = nums.size();
        int dp[n + 1];
        dp[0] = 0;
        int ans = 0;

        for(int i = 1; i <= n; ++i)
        {
            dp[i] = 1;
            for(int j = 1; j < i; ++j)
                if(nums[i - 1] > nums[j - 1])
                    dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
            //cout<<dp[i]<<endl;
        }

        return ans;
    }
};