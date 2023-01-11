class Solution {
public:
    int distinctSubseqII(string s) {

        int n = s.size();
        long long dp[27];
        memset(dp, 0, sizeof(dp));
        int mod = 1e9 + 7;

        for(int i = n - 1; i >= 0; --i)
        {
            int k = s[i] - 'a';
            int prev = dp[k];
            dp[k] = dp[26] + 1;
            dp[26] = (dp[26] + dp[k] - prev) % mod;
        }

        return (dp[26] + mod) % mod;
    }
};