class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        int maxJob[n][n];
        for(int i = 0; i < n; ++i)
        {
            int curMax = jobDifficulty[i];
            for(int j = i; j < n; ++j)
            {
                curMax = max(curMax, jobDifficulty[j]);
                maxJob[i][j] = curMax;
            }
        }

        int dp[n + 1][d + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                for(int k = 1; k <= d; ++k)
                {
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + maxJob[j][i - 1]);
                }
            }
        }

        return dp[n][d];
    }
};