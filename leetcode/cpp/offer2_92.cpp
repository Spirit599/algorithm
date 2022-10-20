class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int n = s.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
            {
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = min(dp[i][0], dp[i][1]) + 1;
            }
            else
            {
                dp[i + 1][0] = dp[i][0] + 1;
                dp[i + 1][1] = min(dp[i][0], dp[i][1]);
            }
        }

        return min(dp[n][0], dp[n][1]);
    }
};