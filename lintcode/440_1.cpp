// 440 · 背包问题 III
// 多重背包
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackIII(int m, vector<int> &a, vector<int> &v) {
        
        int n = a.size();
        int dp[m + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            for(int j = m; j >= a[i]; --j)
            {
                for(int k = 1; k * a[i] <= m; ++k)
                {
                    if(j - k * a[i] >= 0)
                        dp[j] = max(dp[j], dp[j - k * a[i]] + k * v[i]);
                }
                
            }
        }

        return dp[m];
    }
};