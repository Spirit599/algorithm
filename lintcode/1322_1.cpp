// 1322 · 乘积为B

class Solution {
public:
    /**
     * @param b: the all Ai product equal to B
     * @param a: the positive int array
     * @return: return the minium cost 
     */
    int getMinCost(int b, vector<int> &a) {
        
        int n = a.size();
        vector<int> factor;
        for(int i = 1; i <= b; ++i)
        	if(b % i == 0)
        		factor.push_back(i);

        int m = factor.size();

        int dp[n][m];
        memset(dp, 0x3f, sizeof(dp));


        for(int i = 0; i < n; ++i)
        {
        	for(int j = 0; j < m; ++j)
        	{
        		if(i == 0)
        		{
        			dp[0][j] = abs(a[i] - factor[j]);
        			continue;
        		}

        		for(int k = 0; k <= j; ++k)
        		{
        			if(factor[j] % factor[k] == 0)
        			{
        				dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - factor[j] / factor[k]));
        			}
        		}
        	}
        }

        return dp[n - 1][m - 1];
    }
};