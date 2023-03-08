class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {

        int dp[2];
        memset(dp, 0, sizeof(dp));
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int left = i ? nums[i - 1] : INT_MAX;
            int right = i < n - 1 ? nums[i + 1] : INT_MAX;

            dp[i % 2] += max(nums[i] - min(left, right) + 1, 0);
        }

        return min(dp[0], dp[1]);
    }
};