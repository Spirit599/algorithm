//动态规划
//区间dp

class Solution {
public:
    int getMoneyAmount(int n) {

        int dp[n + 1][n + 1];
        memset(dp, 0x3f, sizeof(dp));

        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int start = 1; start + len - 1 <= n; ++start)
            {
                int end = start + len - 1;
                for (int k = 0; k < len; ++k)
                {
                    int guess = start + k;
                    if(guess != start && guess != end)
                        dp[start][end] = min(dp[start][end], max(dp[start][guess - 1], dp[guess + 1][end]) + guess);
                    else if(guess == start)
                        dp[start][end] = min(dp[start][end], dp[guess + 1][end] + guess);
                    else if(guess == end)
                        dp[start][end] = min(dp[start][end], dp[start][guess - 1] + guess);
                }
                cout<<start<<" "<<end<<" "<<dp[start][end]<<endl;
            }
        }

        return dp[1][n];
    }
};