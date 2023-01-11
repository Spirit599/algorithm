const int MOD = 1000000007;
class Solution {
public:
    int distinctSubseqII(string s) {

        int n = s.size();
        long long dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        long long ans = 1;
        for(int i = 1; i < n; ++i)
        {

            bool firstC = true;
            for(int j = i - 1; j >= 0; --j)
            {
                dp[i] = (dp[i] + dp[j]) % MOD;
                if(s[i] == s[j])
                {
                    firstC = false;
                    break;
                }
            }
            if(firstC)
                ++dp[i];
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};