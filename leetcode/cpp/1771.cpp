class Solution {
public:
    int longestPalindrome(string word1, string word2) {

        int n1 = word1.size();
        int n2 = word2.size();




        int dpw1[n1 + 1][n1 + 1];
        memset(dpw1, 0, sizeof(dpw1));
        for(int i = 0; i < n1; ++i)
            dpw1[i][i] = 1;

        for(int len = 2; len <= n1; ++len)
        {
            for(int start = 0; start + len - 1 < n1; ++start)
            {
                int end = start + len - 1;
                if(word1[start] == word1[end])
                    dpw1[start][end] = dpw1[start + 1][end - 1] + 2;
                else
                    dpw1[start][end] = max(dpw1[start + 1][end], dpw1[start][end - 1]);
            }
        }
        

        int dpw2[n2 + 1][n2 + 1];
        memset(dpw2, 0, sizeof(dpw2));
        for(int i = 0; i < n2; ++i)
            dpw2[i][i] = 1;

        for(int len = 2; len <= n2; ++len)
        {
            for(int start = 0; start + len - 1 < n2; ++start)
            {
                int end = start + len - 1;
                if(word2[start] == word2[end])
                    dpw2[start][end] = dpw2[start + 1][end - 1] + 2;
                else
                    dpw2[start][end] = max(dpw2[start + 1][end], dpw2[start][end - 1]);
            }
        }

        int dp[n1][n2];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n1; ++i)
        {
            for(int j = n2 - 1; j >= 0; --j)
            {
                if(word1[i] == word2[j])
                {
                    dp[i][j] = 2;
                    if(i != 0 && j != n2 - 1)
                        dp[i][j] += dp[i - 1][j + 1];
                }
                else
                {
                    if(i != 0)
                        dp[i][j] = dp[i - 1][j];
                    if(j != n2 - 1)
                        dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n1; ++i)
        {
            if(dp[i][0] != 0)
            {
                ans = max(ans, dp[i][0] + dpw1[i + 1][n1 - 1]);
            }
        }


        for(int i = 0; i < n2; ++i)
        {
            
            if(i)
            {
                if(dp[n1 - 1][i] != 0)
                {
                    ans = max(ans, dp[n1 - 1][i] + dpw2[0][i - 1]);
                }
            }
            else
            {
                ans = max(ans, dp[n1 - 1][i]);
            }
        }
        printf("%d",dp[n1 - 1][0]);

        return ans;
    }
};