const int MOD = 1e9 + 7;
class Solution {
public:
    int countTexts(string pressedKeys) {
        
        int n = pressedKeys.size();
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 0; i < n; ++i)
        {
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
            if(i >= 1 && pressedKeys[i] == pressedKeys[i - 1])
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
            if(i >= 2 && pressedKeys[i] == pressedKeys[i - 1] && pressedKeys[i] == pressedKeys[i - 2])
                dp[i + 1] = (dp[i + 1] + dp[i - 2]) % MOD;
            if(i >= 3 && (pressedKeys[i] == '7' || pressedKeys[i] == '9') && pressedKeys[i] == pressedKeys[i - 1] && pressedKeys[i] == pressedKeys[i - 2] && pressedKeys[i] == pressedKeys[i - 3])
                dp[i + 1] = (dp[i + 1] + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};