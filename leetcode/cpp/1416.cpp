class Solution {
public:
    int numberOfArrays(string s, int k) {

        int n = s.size();
        int dp[n + 1];
        int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
                continue;

            long long num = 0;
            int j = i;
            while(j < n)
            {
                num = 10 * num + s[j] - '0';
                if(num > k)
                    break;
                dp[j + 1] = (dp[j + 1] + dp[i]) % mod;
                ++j;
            }
        }

        return dp[n];
    }
};