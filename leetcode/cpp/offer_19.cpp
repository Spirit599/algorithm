class Solution {
public:
    bool isMatch(string s, string p) {

        int n1 = s.size();
        int n2 = p.size();

        bool dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int j = 1; j < n2; ++j)
            if(p[j] == '*')
                dp[0][j + 1] = dp[0][j - 1];

        for(int i = 0; i < n1; ++i)
        {
            for(int j = 0; j < n2; ++j)
            {
                if(s[i] == p[j] || p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if(p[j] == '*')
                {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    if((s[i] == p[j - 1] || p[j - 1] == '.'))
                        dp[i + 1][j + 1] |= dp[i][j + 1];
                }

            }
        }

        return dp[n1][n2];
    }
};