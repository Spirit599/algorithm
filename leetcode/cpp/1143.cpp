class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.size();
        int n2 = text2.size();
        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n1; ++i)
        {
            for(int j = 0; j < n2; ++j)
            {
                if(text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[n1][n2];
    }
};