class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

    	int n = stones.size();
    	int k = accumulate(stones.begin(), stones.end(), 0);
    	bool dp[n + 1][k + 1];
    	memset(dp, 0, sizeof(dp));
    	dp[0][0] = true;

    	for(int i = 0; i < n; ++i)
    	{
    		for(int j = 0; j <= k; ++j)
    		{
    			if(j < stones[i])
    				dp[i + 1][j] = dp[i][j];
    			else
    				dp[i + 1][j] = dp[i][j] || dp[i][j - stones[i]];
    			
    		}
    	}

    	int ans = k;
    	for(int i = 0; i <= k; ++i)
    	{
    		if(dp[n][i])
    		{
    			ans = min(ans, abs(i - (k - i)));
    		}
    	}
    	return ans;
    }
};