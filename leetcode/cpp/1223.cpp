class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {


        int dp[n][6][16];
        memset(dp, 0, sizeof(dp));
        int mod = 1e9 + 7;

        for(int i = 0; i < 6; ++i)
            dp[0][i][1] = 1;

        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                for(int k = 0; k < 6; ++k)
                {
                    if(j != k)
                    {
                        for(int l = 1; l <= rollMax[j]; ++l)
                        {
                            dp[i][k][1] += dp[i - 1][j][l];
                            dp[i][k][1] %= mod;
                        }
                    }
                    else
                    {
                        for(int l = 1; l < rollMax[j]; ++l)
                        {
                            dp[i][k][l + 1] += dp[i - 1][j][l];
                            dp[i][k][l + 1] %= mod;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 6; ++i)
        {
            for(int j = 1; j <= rollMax[i]; ++j)
            {
                ans += dp[n - 1][i][j];
                ans %= mod;
            }
        }

        return ans;
    }
};