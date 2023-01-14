class Solution {
public:
    int minDistance(string word1, string word2) {

    	int n1 = word1.size();
    	int n2 = word2.size();


    	int dp[n1 + 1][n2 + 1];
    	memset(dp, 0x3f, sizeof(dp));
    	dp[0][0] = 0;
    	for(int i = 0; i <= n1; ++i)
    		dp[i][0] = i;
    	for(int i = 0; i <= n2; ++i)
    		dp[0][i] = i;


    	for(int i = 0; i < n1; ++i)
    	{
    		for(int j = 0; j < n2; ++j)
    		{
    			if(word1[i] == word2[j])
    				dp[i + 1][j + 1] = dp[i][j];
    			else
    				dp[i + 1][j + 1] = min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1;
    		}
    	}

    	return dp[n1][n2];
    }
};