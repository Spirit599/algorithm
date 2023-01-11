// 10. 正则表达式匹配
//字符串DP

class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        bool dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int j = 0; j < n; ++j)
            if(j >= 1 && p[j] == '*')
                dp[0][j + 1] = dp[0][j - 1];

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(s[i] == p[j] || p[j] == '.')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if(p[j] == '*')
                {
                    bool flag;
                    if(j > 0 && (p[j - 1] == s[i] || p[j - 1] == '.'))
                        flag = dp[i][j + 1];
                    else
                        flag = false;
                    dp[i + 1][j + 1] = flag || dp[i + 1][j - 1]; //|| dp[i + 1][j];
                }
                else
                {
                    dp[i + 1][j + 1] = false;
                }
                cout<<i + 1<<" "<<j + 1<<" "<<dp[i + 1][j + 1]<<endl;
            }
        }

        return dp[m][n];
    }
};