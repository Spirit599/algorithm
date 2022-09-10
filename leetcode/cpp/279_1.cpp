//279. 完全平方数

class Solution {
public:
    int numSquares(int n) {

        int dp[n + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        vector<int> coins;
        for(int i = 1; i * i <= n; ++i)
            coins.push_back(i * i);

        for(int i = 1; i <= n; ++i)
        {
            for(int coin : coins)
            {
                if(i - coin >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[n];
    }
};