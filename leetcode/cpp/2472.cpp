class Solution {
public:
    int maxPalindromes(string s, int k) {
        

        int n = s.size();
        bool isPalin[n][n];
        memset(isPalin, 0, sizeof(isPalin));

        for(int i = 0; i < n; ++i)
        {
            isPalin[i][i] = true;
            if(i > 0 && s[i] == s[i - 1])
                isPalin[i - 1][i] = true;
        }
        for(int len = 3; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                if(s[start] == s[end])
                    isPalin[start][end] = isPalin[start + 1][end - 1];
            }
        }

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for(int j = k - 1; j < n; ++j)
        {
            dp[j + 1] = dp[j];

            int i = j - k + 1;
            for(int start = i; start >= 0; -- start)
            {
                if(isPalin[start][j])
                {
                    dp[j + 1] = max(dp[j + 1], dp[start] + 1);
                    break;
                }
            }
        }

        return dp[n];
    }
};