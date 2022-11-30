class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        int dp[m + 1][n + 1][target + 1];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][n][0] = 0; 
        int inf = 0x3f3f3f3f;
        int sub = 0;

        for(int k = 0; k < m; ++k)
        {
            int house = houses[k];
            int start = house - 1;
            int end = house - 1;
            if(house == 0)
            {
                start = 0;
                end = n - 1;
            }
            else
            {
                sub += cost[k][start];
            }
            for(int i = start; i <= end; ++i)
            {
                for(int j = 0; j <= n; ++j)
                {
                    if(i == j)
                    {
                        for(int l = 0; l <= target; ++l)
                        {
                            dp[k + 1][i][l] = min(dp[k + 1][i][l], dp[k][j][l] + cost[k][i]);
                        }
                    }
                    else
                    {
                        for(int l = 0; l < target; ++l)
                        {
                            dp[k + 1][i][l + 1] = min(dp[k + 1][i][l + 1], dp[k][j][l] + cost[k][i]);
                        }
                    }
                }
            }
        }


        int ans = inf;
        for(int i = 0; i < n; ++i)
            ans = min(ans, dp[m][i][target]);

        if(ans != inf)
            return ans - sub;
        else
            return -1;
    }
};