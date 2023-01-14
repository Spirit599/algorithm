class Solution {
public:
    bool isMatch(string s, string p) {

    	int n = s.size();
    	int m = p.size();

    	bool dp[n + 1][m + 1];
    	memset(dp, 0, sizeof(dp));
    	dp[0][0] = true;
    	for(int i = 0; i < m; ++i)
    	{
    		if(p[i] != '*')
    			break;
    		dp[0][i + 1] = true;
    	}

    	for(int i = 0; i < n; ++i)
    	{
    		for(int j = 0; j < m; ++j)
    		{
    			if(p[j] == '?' || p[j] == s[i])
    			{
    				dp[i + 1][j + 1] = dp[i][j];
    			}
    			else if(p[j] == '*')
    			{
    				dp[i + 1][j + 1] = dp[i + 1][j] | dp[i][j + 1];
    			}
    		}
    	}

    	return dp[n][m];

    }
};