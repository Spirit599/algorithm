class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {

        int m = cost.size();
        int n = cost[0].size();

        int S = 1 << n;
        int dp[m + 1][S];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;

        int sum[m][S];
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < m; ++i)
        {
            for(int mask = 1; mask < S; ++mask)
            {
                for(int bit = 0; bit < n; ++bit)
                {
                    if(mask & (1 << bit))
                    {
                        sum[i][mask] = sum[i][mask ^ (1 << bit)] + cost[i][bit];
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i)
        {
            for(int mask = 0; mask < S; ++mask)
            {
                for(int subset = mask; subset != 0; subset = (subset - 1) & mask)
                {
                    int preSubset = mask ^ subset;
                    dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][preSubset] + sum[i][subset]);
                }

                for(int bit = 0; bit < n; ++bit)
                {
                    if(mask & (1 << bit))
                    {
                        dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask] + cost[i][bit]);
                    }
                }
            }
        }

        return dp[m][S - 1];
    }
};