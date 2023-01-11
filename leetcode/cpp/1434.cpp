class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {

        int n = hats.size();
        int hatSize = 40;
        vector<int> hatsToPerson[hatSize + 1];
        
        for(int i = 0; i < n; ++i)
        {
            for(int hat : hats[i])
            {
                hatsToPerson[hat].emplace_back(i);
            }
        }

        int mod = 1e9 + 7;
        int S = 1 << n;
        int dp[hatSize + 1][S];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= hatSize; ++i)
        {
            memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
            for(int p : hatsToPerson[i])
            {
                for(int mask = 0; mask < S; ++mask)
                {
                    if((mask & (1 << p)) == 0)
                    {
                        dp[i][mask | (1 << p)] = (dp[i][mask | (1 << p)] + dp[i - 1][mask]) % mod;
                    }
                }
            }
        }

        return dp[hatSize][S - 1];


    }
};