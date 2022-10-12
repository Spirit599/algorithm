// 剑指 Offer II 094. 最少回文分割

class Solution {
public:
    int minCut(string s) {

        int n = s.size();
        bool isPalindrome[n][n];
        memset(isPalindrome, 0, sizeof(isPalindrome));
        for(int i = 0; i < n; ++i)
            isPalindrome[i][i] = true;
        for(int length = 2; length <= n; ++length)
        {
            for(int start = 0; start + length - 1 < n; ++start)
            {
                int end = start + length - 1;
                // printf("%d %d\n", start, end);
                if(length == 2)
                    isPalindrome[start][end] = (s[start] == s[end]);
                else
                    isPalindrome[start][end] = isPalindrome[start + 1][end - 1] && (s[start] == s[end]);
            }
        }

        int dp[n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                // printf("%d %d ", i,j);
                if(isPalindrome[j][i])
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                // printf("%d\n", dp[i + 1]);
            }
        }


        return dp[n] - 1;
    }
};