// 鸡蛋

class Solution {
public:
    int superEggDrop(int k, int n) {

        int dp[k + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
            dp[1][i] = i;

        for(int i = 2; i <= k; ++i)
        {
            int optX = 1;
            for(int j = 1; j <= n; ++j)
            {
                while(optX < j && max(dp[i][j - optX], dp[i - 1][optX - 1]) > 
                    max(dp[i][j - optX - 1], dp[i - 1][optX]))
                    ++optX;
                dp[i][j] = 1 + max(dp[i][j - optX], dp[i - 1][optX - 1]);
            }
        }

        return dp[k][n];
    }
};