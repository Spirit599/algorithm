// 125 · 背包问题（二）

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &a, vector<int> &v) {
        
        int n = a.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                if(a[i] <= j)
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - a[i]] + v[i]);
                else
                    dp[i + 1][j] = dp[i][j];
            }
        }

        return dp[n][m];
    }
};