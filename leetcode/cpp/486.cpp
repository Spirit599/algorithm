class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();
        int dp[n][n];
        for(int i = 0; i < n; ++i)
            dp[i][i] = nums[i];

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                dp[start][end] = max(nums[end] - dp[start][end - 1], nums[start] - dp[start + 1][end]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};