class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int sum1 = 0;
        int sum2 = 0;
        int n1 = s1.size();
        int n2 = s2.size();

        for(int i = 0; i < n1; ++i)
            sum1 += s1[i];
        for(int i = 0; i < n2; ++i)
            sum2 += s2[i];

        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n1; ++i)
        {
            for(int j = 0; j < n2; ++j)
            {
                if(s1[i] == s2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + s1[i];
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return sum1 + sum2 - 2 * dp[n1][n2];
    }
};