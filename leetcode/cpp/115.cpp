class Solution {
public:
    int numDistinct(string s, string t) {

        int n = t.size();
        unsigned long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(char c : s)
        {
            for(int i = n; i >= 1; --i)
            {
                //printf("%d\n", i);
                if(c == t[i - 1])
                    dp[i] += dp[i - 1];
            }
        }

        return dp[n];

    }
};