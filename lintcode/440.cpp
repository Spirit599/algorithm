// 440 · 背包问题 III
// 完全背包
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackIII(vector<int> &a, vector<int> &v, int m) {
        
        int n = a.size();
        int dp[m + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            for(int j = a[i]; j <= m; ++j)
            {
                dp[j] = max(dp[j], dp[j - a[i]] + v[i]);
            }
        }

        return dp[m];
    }
};