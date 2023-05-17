class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {

        
        int n = stones.size();
        if((n - 1) % (k - 1))
            return -1;

        int preSum[n + 1];
        preSum[0] = 0;
        for(int i = 1; i <= n; ++i)
            preSum[i] = preSum[i - 1] + stones[i - 1];

        int dp[n][n];
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 0;

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                for(int split = start; split < end; split += (k - 1))
                {
                    dp[start][end] = min(dp[start][end], dp[start][split] + dp[split + 1][end]);
                }

                if((len - 1) % (k - 1) == 0)
                    dp[start][end] += preSum[end + 1] - preSum[start];

                printf("%d %d %d\n", start,end,dp[start][end]);
            }
        }

        return dp[0][n - 1];
    }
};