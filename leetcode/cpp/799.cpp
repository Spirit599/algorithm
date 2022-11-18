class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        double dp[query_row + 2][query_row + 2];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = poured;
        for(int row = 0; row <= query_row; ++row)
        {
            for(int col = 0; col <= row; ++col)
            {
                if(dp[row][col] > 1)
                {
                    double add = (dp[row][col] - 1) / 2;
                    dp[row][col] = 1;
                    dp[row + 1][col] += add;
                    dp[row + 1][col + 1] += add;
                }
            }
        }

        return dp[query_row][query_glass];
    }
};