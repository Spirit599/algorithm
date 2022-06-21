//476 · 石子归并

class Solution {
public:
    /**
     * @param a: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &a) {
        
        int n = a.size();
        int dp[n][n];
        memset(dp, 0x3f, sizeof(dp));
        int pre_sum[n];
        int sum = 0;

        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 0;
            sum += a[i];
            pre_sum[i] = sum;
        }

        for(int length = 2; length <= n; ++length)
        {
            for(int start = 0; start + length - 1 < n; ++start)
            {
                int end = start + length - 1;
                for(int splice = start; splice < end; ++splice)
                {
                    dp[start][end] = min(dp[start][end], dp[start][splice]  + dp[splice + 1][end] +
                                                            pre_sum[end] - pre_sum[start] + a[start]);
                }
            }
        }

        return dp[0][n - 1];
    }
};