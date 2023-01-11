class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {

        int n = binary.size();
        int dp[2];
        memset(dp, 0, sizeof(dp));
        int mod = 1e9 + 7;
        bool haveZero = false;

        for(int i = n - 1; i >= 0; --i)
        {
            int num = binary[i] - '0';
            if(num == 1)
            {
                dp[1] = (dp[1] + dp[0] + 1) % mod;
            }
            else
            {
                haveZero = true;
                dp[0] = (dp[1] + dp[0] + 1) % mod;
            }
        }

        if(haveZero)
            dp[0] = 1;

        return dp[1] + dp[0];
    }
};