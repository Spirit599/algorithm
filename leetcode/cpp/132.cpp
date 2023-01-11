class Solution {
public:
    int minCut(string s) {

        int n = s.size();
        bool isPali[n + 1][n + 1];
        memset(isPali, 0, sizeof(isPali));

        for(int i = 0; i < n; ++i)
        {
            isPali[i][i] = true;
            if(i + 1 < n && s[i] == s[i + 1])
                isPali[i][i + 1] = true;
        }

        for(int len = 3; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                if(s[start] == s[end] && isPali[start + 1][end - 1])
                {
                    isPali[start][end] = true;
                    //printf("%d %d\n", start,end);
                }
            }
        }

        int dp[n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                if(isPali[j][i])
                {
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                }
            }
        }


        return dp[n] - 1;
    }
};