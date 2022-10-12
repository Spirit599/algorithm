// LCP

class Solution {
public:
    int deleteString(string s) {
       
        int n = s.size();
        int lcp[n + 1][n + 1];
        memset(lcp, 0, sizeof(lcp));
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = n - 1; j > i; --j)
            {
                if(s[i] == s[j])
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[n - 1] = 1;

        for(int i = n - 2; i >= 0; --i)
        {
            dp[i] = 1;
            for(int length = 1; length <= n / 2; ++length)
            {
                if(i + 2 * length > n)
                    break;
                // if(s.substr(i, length) == s.substr(i + length, length))
                //     dp[i] = max(dp[i], dp[i + length] + 1);
                if(lcp[i][i + length] >= length)
                    dp[i] = max(dp[i], dp[i + length] + 1);
            }
        }

        return dp[0];
    }
};