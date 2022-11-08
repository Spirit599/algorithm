// 安排位置
// dp;

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {

        sort(houses.begin(), houses.end());
        int n = houses.size();

        int preSum[n + 1];
        preSum[0] = 0;
        for(int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + houses[i];

        int dp[k + 1][n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;

        function<int(int, int)> helper = [&](int left, int right) {

            int midIndex = (right + left) >> 1;
            if((right + left) & 1)
                return (preSum[right + 1] - preSum[midIndex + 1]) - (preSum[midIndex + 1] - preSum[left]);
            else
                return (preSum[right + 1] - preSum[midIndex + 1]) - (preSum[midIndex] - preSum[left]);
        };


        for(int i = 0; i < k; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                for(int l = j - 1; l >= 0; --l)
                {
                    // printf("%d %d\n", l, j - 1);
                    int val = helper(l, j - 1);
                    // printf("%d %d %d\n", l, j - 1, val);
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][l] + val);
                }
            }
        }

        return dp[k][n];
    }
};