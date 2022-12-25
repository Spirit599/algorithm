class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {

        int n = stones.size();
        if(n % (k - 1) != 1 && k != 2)
            return -1;


        int preSum[n + 1];
        preSum[0] = 0;

        for(int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + stones[i];

        int dp[n][n][k + 1];
        memset(dp, 0x3f, sizeof(dp));

        for(int i = 0; i < n; ++i)
            dp[i][i][1] = 0;

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                for(int batch = 2; batch <= k; ++batch)
                {
                    for(int split = start; split < end; split += (k - 1))
                    {
                        dp[start][end][batch] = min(dp[start][end][batch], dp[start][split][1] + dp[split + 1][end][batch - 1]);
                    }
                }
                dp[start][end][1] = dp[start][end][k] + preSum[end + 1] - preSum[start];
            }
        }

        return dp[0][n - 1][1];
    }
};