class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
            dp[i][i] = piles[i];

        for(int len = 2; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                dp[start][end] = max(piles[start] - dp[start + 1][end], 
                                    piles[end] - dp[start][end - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }
};