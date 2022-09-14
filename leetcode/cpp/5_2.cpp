class Solution {
public:
    string longestPalindrome(string s) {

        int ans = 1;
        int n = s.size();

        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int left = 0;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            if(i + 1 < n && s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                ans = 2;
                left = i;
            }
        }

        for(int length = 3; length <= n; ++length)
        {
            for(int start = 0; start + length - 1 < n; ++start)
            {
                int end = start + length - 1;
                if(s[start] == s[end] && dp[start + 1][end - 1])
                {
                    dp[start][end] = true;
                    ans = length;
                    left = start;
                }
            }
        }

        return s.substr(left, ans);
    }
};