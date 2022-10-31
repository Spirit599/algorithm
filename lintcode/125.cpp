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
        int dp[m + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            for(int j = m; j >= a[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - a[i]] + v[i]);
            }
        }

        return dp[m];
    }
};