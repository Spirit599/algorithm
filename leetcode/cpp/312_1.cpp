// 312. 戳气球

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        int dp[n + 2][n + 2];

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, 0, sizeof(dp));

        for(int length = 1; length <= n; ++length)
        {
            for(int start = 1; start + length - 1 <= n; ++start)
            {
                int end = start + length - 1;
                for(int split = start; split <= end; ++split)
                {
                    int sum = nums[split] * nums[start - 1] * nums[end + 1];
                    dp[start][end] = max(dp[start][end], sum + dp[start][split - 1] + dp[split + 1][end]);
                }
            }
        }

        return dp[1][n];
    }
};