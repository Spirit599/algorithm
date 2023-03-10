// 多重背包

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int mod = 1e9 + 7;

        for(auto& type : types)
        {
            int cnt = type[0];
            int k = type[1];
            for(int i = target; i >= k; --i)
            {
                for(int j = 1; j * k <= target && j <= cnt; ++j)
                {
                    if(i - j * k >= 0)
                    {
                        dp[i] += dp[i - j * k];
                        dp[i] %= mod;
                    }
                }
            }
        }

        // for(int i = 0; i <= target; ++i)
        //     printf("%d ", dp[i]);
        // printf("\n");

        return dp[target];
    }
};