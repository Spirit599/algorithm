class Solution {
public:
    int getMoneyAmount(int n) {

        int dp[n + 1][n + 1];

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(i < j)
                    dp[i][j] = INT_MAX;
                else
                    dp[i][j] = 0;
            }
        }
        

        for (int length = 2; length <= n; ++length)
        {
            for (int start = 0; start + length - 1 <= n; ++start)
            {
                int end = start + length - 1;
                for (int guess = start; guess <= end; ++guess)
                {
                    int cost;
                    if(guess != start && guess != end)
                        cost = guess + max(dp[start][guess - 1], dp[guess + 1][end]);
                    else if(guess == start)
                        cost = guess + dp[guess + 1][end]; 
                    else
                        cost = guess + dp[start][guess - 1]; 
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }



        return dp[1][n];
    }
};