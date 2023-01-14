class Solution {
public:
    int numDistinct(string s, string t) {

    	int n = t.size();
    	unsigned long long dp[n + 1];
    	memset(dp, 0, sizeof(dp));
    	dp[0] = 1;

    	for(char c : s)
    	{
    		for(int i = n - 1; i >= 0; ++i)
    		{
    			if(c == t[i])
    			{
    				dp[i + 1] += dp[i];
    			}
    		}
    	}

    	return dp[n];
    }
};