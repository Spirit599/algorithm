class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &a) {
        
    	int n = a.size();
        int dp[m + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
        	for(int j = m; j >= a[i]; --j)
        	{
        		dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        	}
        }

        return dp[m];
        
    }
};