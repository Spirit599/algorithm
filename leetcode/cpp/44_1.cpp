class Solution {
public:
    bool isMatch(string s, string p) {

        int s_size = s.size();
        int p_size = p.size();

        bool dp[s_size + 1][p_size + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = true;

        for (int i = 1; i < p_size + 1; ++i)
        {
            /* code */
            if(p[i - 1] == '*')
            {
                dp[0][i] = true;
            }
            else
            {
                break;
            }
        }


        for (int i = 1; i < s_size + 1; ++i)
        {
            for (int j = 1; j < p_size + 1; ++j)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        for (int i = 0; i < s_size + 1; ++i)
        {
            for (int j = 0; j < p_size + 1; ++j)
            {
                cout<<dp[i][j]<<endl;
            }
        }

        return dp[s_size][p_size];
    }
};