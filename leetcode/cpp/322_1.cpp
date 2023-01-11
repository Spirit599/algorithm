//322. 零钱兑换

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

    	int dp[amount + 1];
    	memset(dp, 0x3f, sizeof(dp));
    	dp[0] = 0;

for(int i = 1; i <= amount; ++i)
{
	for(int coin : coins)
	{
		if(i - coin >= 0)
		{
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
}

    	if(dp[amount] != 0x3f)
    		return dp[amount];
    	else
    		return -1;
    }
};