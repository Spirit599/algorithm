class Solution {
public:

    bool winnerSquareGame(int n) {

        int dp[n + 1];
        memset(dp, -1, sizeof(dp));

        function<int(int)> dfs = [&](int n) -> int {

            if(dp[n] != -1)
                return dp[n];
            if(n == 0)
                return false;

            int maxn = sqrt(n);
            for(int i = maxn; i >= 1; --i)
            {
                if(!dfs(n - i * i))
                    return dp[n] = true;
            }

            return dp[n] = false;
        };

        return dfs(n);
    }
};