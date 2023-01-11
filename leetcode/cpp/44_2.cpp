class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        bool dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = true;
        for(int j = 0; j < n; ++j)
        {
            if(p[j] == '*')
                dp[0][j + 1] = true;
            else
                break;
        }


        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(s[i] == p[j] || p[j] == '?')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if(p[j] == '*')
                {
                    dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }

        return dp[m][n];

    }
};