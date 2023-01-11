const int mod = 1e9 + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int split) {

        int m = pizza.size();
        int n = pizza[0].size();
        int preSum[m + 1][n + 1];
        memset(preSum, 0, sizeof(preSum));
        int dp[m + 1][n + 1][split + 1];
        memset(dp, -1, sizeof(dp));

        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                preSum[i][j] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }

        function<int(int, int, int)> dfs = [&](int x, int y, int k) -> int {

            if(preSum[x][y] < k)
                return 0;
            if(k == 1)
                return 1;
            if(dp[x][y][k] != -1)
                return dp[x][y][k];

            int ret = 0;
            int sum = preSum[x][y];
            for(int i = m - 1; i > x; --i)
            {
                if(preSum[i][y] != sum)
                {
                    ret += dfs(i, y, k - 1);
                    ret %= mod;
                }
                else break;

            }
            for(int j = n - 1; j > y; --j)
            {
                if(preSum[x][j] != sum)
                {
                    ret += dfs(x, j, k - 1);
                    ret %= mod;
                }
                else break;

            }

            // printf("%d %d %d %d\n", x,y,k,ret);
            return dp[x][y][k] = ret;

        };

        return dfs(0, 0, split);
    }
};