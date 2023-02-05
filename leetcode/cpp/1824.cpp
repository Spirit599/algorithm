class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {

    	int n = obstacles.size();
    	int dp[n][4];
    	memset(dp, 0x3f, sizeof(dp));
    	dp[0][2] = 0;
    	dp[0][1] = 1;
    	dp[0][3] = 1;
    	for(int i = 1; i < n; ++i)
    	{
    		for(int j = 1; j < 4; ++j)
    		{
    			if(obstacles[i] != j)
    			{
    				dp[i][j] = dp[i - 1][j];
    			}
    		}
    		if(obstacles[i] != 1)
    			dp[i][1] = min(dp[i][1], min(dp[i][2], dp[i][3]) + 1);
    		if(obstacles[i] != 2)
    			dp[i][2] = min(dp[i][2], min(dp[i][1], dp[i][3]) + 1);
    		if(obstacles[i] != 3)
    			dp[i][3] = min(dp[i][3], min(dp[i][2], dp[i][1]) + 1);
    	}

    	return min({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
    }
};